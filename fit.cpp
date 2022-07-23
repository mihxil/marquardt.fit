/* marquardt fit
    
   november 1998 Michiel Meeuwissen, based on lmq4a.f
 
   This program fits, using the NR mrqmin funcion,  the function qcalc to the data incoming on 
   standard input.
   (something like 'get.aspectratio' produces:
    l  Q            dQ           K          ignored by this program
  
    3  0.64864003  0.00038064  3.04400000   2.0 li 2
    4  0.64207996  0.00042546  3.04400000   2.0 li 2
    6  0.63685417  0.00039124  3.04400000   2.0 li 3
    7  0.63424182  0.00043149  3.04400000   2.0 li 3
    8  0.63257334  0.00041079  3.04400000   2.0 li 4
    9  0.63039576  0.00044132  3.04400000   2.0 li 4
    ...
  )
       
*/
#include <math.h>
#include <vector>
#include <t_mrqmin.h>
#include <iostream.h>
#include <stack>
#include <string>

#include "cmdln.h"
#include "qcalc.h"
#include "f2calc.h"


int countNumberOfFreeParameters(int * ia, int npar)
{
  int mfit = 0;
  for(int i = 1; i <= npar; i++) if (ia[i]) mfit ++; 
  return mfit;
}

/*
  The real fit-function:
 */
template<class floatt, class F, class V>
void fit(int npar, V vars, int nmaxiter)
{
  // a few vectors. We call nr_vector which is the templatized NR function vector..
  floatt * a      = nr_vector<floatt>(1,npar);   // parameters (called 'a' by NR)
  int    * ia     = nr_vector<int>(1,npar);      // which should be fitted      
  
  // matrices needed by NR.
  floatt ** covar = nr_matrix<floatt>(1,npar,1,npar);
  floatt ** alpha = nr_matrix<floatt>(1,npar,1,npar);
  string descr_of_a[npar+1]; // well, one two many, we simply don't use descr_of_a[0]..
  
  // Initalize some parameters:
  F::init(descr_of_a, a, ia, &vars);
  // the data
  typename F::xtype* x;   // function arguments (in this case k and l)     
  // these are same for all functions:
  floatt * y;   // to be fitted points
  floatt * sig; // their error 
  int ndata; // number of points.
    // read data from standard input (and allocate memory for it):
  F::read(&x,&y,&sig, &ndata, &vars);
    

  //-----------------------------------------------------
  floatt chisqr, ochisqr, dchisqr;
  
  // one initial call (See NR 15.5 for commence on how using mrqmin)
  floatt alamda = -1;
  mrqmin<floatt, typename F::xtype>
    (x,y,sig,ndata, a, ia, npar, covar, alpha, &chisqr, F::function, &alamda);
  // loop till convergence or too many iterations
  ochisqr = chisqr;    
  dchisqr = -1;
  int iter = 0;  // number of iterations done.  
    
  while( !(dchisqr > 0 && dchisqr < vars.conv) && iter < nmaxiter)
    {
      mrqmin(x,y,sig,ndata, a, ia, npar, covar, alpha, &chisqr, F::function, &alamda);
      dchisqr = ochisqr-chisqr;
      ochisqr = chisqr; 
      iter++;
    }
  if(iter >= nmaxiter) cout << "**NO CONVERGENCE REACHED **\n";
  
  // a final call to obain the covariances (see also NR).
  alamda = 0;
  mrqmin(x,y,sig,ndata, a, ia, npar, covar, alpha, &chisqr, F::function, &alamda);   

  int mfit = countNumberOfFreeParameters(ia, npar);
  // count number of free variables.

  cout << "\nconvergence: "       << dchisqr 
       << "\nchi squared: "       << chisqr
       << "\nN degr. fr.: "       << (ndata-mfit) // needed for the gammq
       << "\niterations:  "       << iter << endl;  
  F::write(x,y,sig, a, ia, &vars, covar, ndata, descr_of_a, npar );
    
  //-----------------------------------------------------------
}

/*-----------------------------------------------------------------------------------
  MAIN program

 */


int main(int argc, char *argv[])
{
  // 
  int npar; 
  int nmaxiter;
  string helptext = "Program which calls NR mrqmin to fit several functions, depending on its \n"
   "first argument wich can be one of the following (get help via h) \n"
     "   q: " + qcalc::String + 
   "\n   g: " + f2calc::String + 
   "\n version  Michiel Meeuwissen april 1999, based on lmq4a.f \n\n";

  int  mode = c_cmdln::read(argc,argv, (char *)helptext.c_str());  

  switch(mode)	      
    {
    case c_cmdln::c_q :
      {
      npar = 20;        // number of parameters of qcalc (in a)
      nmaxiter=1000;   
      c_q qvars = c_q(argc,argv,
		  "It expects output from 'get.aspectratio' on standard input\n" 
		  "And will give the fit-results on standard output\n" 
		  "use (e.g.): get.aspectratio <ratio> | fit q [options] | most\n"
                  );
      fit<double, qcalc, c_q>(npar, qvars, nmaxiter);            
      }
      break;   
    case c_cmdln::c_f2 :
      {
      npar = 6;        // number of parameters of qcalc (in a)
      nmaxiter=1000;     
      c_f2 f2vars = c_f2(argc, argv,
			  "To fit a polynomal curve with three variables\n\n");
      fit<double, f2calc,c_f2>(npar, f2vars, nmaxiter);
      }
      break;
    default:
      exit(0);
    }

  // we could call nr_freevector an nr_freematrix, but I think the compiler should take care of that.
}/* main */
