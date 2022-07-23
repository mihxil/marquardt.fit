

#include "cmdln.h"
#include "function.h"


// f2 ~ function2   (nice name, isn't it?)
class f2calc : public functiontype
{
 public:
  struct xtype { floatt x; bool formC; };
  
  // This is the function wich we're going to fit.

  // as a string
  static const string String;
  // =  
  // itself
  static void function (xtype x, floatt a[], floatt * y, floatt dyda[], int npar)
    {                
      
      /* some helps */
      floatt xmina = log(x.x) - (x.formC ? a[6] : 0);
      //floatt xmina = x.x - (x.formC ? a[5] : 0); // this works very bad
      floatt xmina2 = xmina * xmina;
      floatt xmina3 = xmina2 * xmina;
      floatt xmina4 = xmina2 * xmina2;

      /* function definition */
      *y =  a[1] + a[2] * xmina + a[3] * xmina2 + a[4] * xmina3 + a[5] * xmina4;

      //      cout << "x: "<< x.x << "formC " << x.formC << " xmina :" << xmina << endl;
      /* derivatives */
      dyda[1] = 1.0;
      dyda[2] = xmina;
      dyda[3] = xmina2;
      dyda[4] = xmina3;
      dyda[5] = xmina4;
      dyda[6] = x.formC ? -a[2] 
                           - 2 * a[3] * xmina 
                           - 3 * a[4] * xmina2 
	                   - 4 * a[5] * xmina3
                        : 0;
      //dyda[5] = x.formC ? -a[2] - 2 * a[3] *  xmina - 3 * a[4] * xmina2 : 0;

      /*
	dyda[1] = -2 * a[2] *  xmina - 3 * a[4] * xmina2 - a[5];  
	dyda[2] = xmina2; 
	dyda[3] = 1.0;
	dyda[4] = xmina3;
	dyda[5] = xmina;
      */
    }
  
  static void init(string * sa, floatt * a, int * ia, void * c)
  //, floatt * Kc, floatt yt, bool fitKc)
    {
      // name        (initial) values        fit yes/no
      sa[1] = "a0";   a[1] = ((c_f2*)c)->a0;    ia[1] = ((c_f2*)c)->fita0;
      sa[2] = "a1";   a[2] = ((c_f2*)c)->a1;    ia[2] = ((c_f2*)c)->fita1;
      sa[3] = "a2";   a[3] = ((c_f2*)c)->a2;    ia[3] = ((c_f2*)c)->fita2;
      sa[4] = "a3";   a[4] = ((c_f2*)c)->a3;    ia[4] = ((c_f2*)c)->fita3;
      sa[5] = "a4";   a[5] = ((c_f2*)c)->a4;    ia[5] = ((c_f2*)c)->fita4;
      sa[6] = "C";    a[6] = ((c_f2*)c)->C;     ia[6] = ((c_f2*)c)->fitC;
     
    }

static void read(xtype ** x, floatt ** y, floatt ** sig, int * ndata, void * c)
  /*
    Reads the data from standard input. Firstly tempory in stacks, and then
    copies it to arrays 
   */
{
  // help variables 
  stack<xtype>  xstack;
  stack<floatt> ystack;
  stack<floatt> sigstack;
  xtype hx;
  floatt hy;
  floatt hsig;
  char achar;
  hx.formC = ((c_f2*)c)->formC;
  while(!cin.eof())
    {
      // we ignore lines beginning with # (to make commence possible)     
      cin >> achar;      
      if(achar== '#'){ while(cin.get() != 10 && !cin.eof()); continue;}	
      
      // if a line starts with 'C' then ignore rest of line and switch 'fitc'.      
      if(achar== 'C')
	{
	  while(cin.get() != 10 && !cin.eof());
	  hx.formC = !hx.formC;
	  continue;
	}	
     
      cin.putback(achar);
             
      cin >> hx.x >>  hy >> hsig; 
    
      if(cin.eof()) break;
      // ignore rest of line      
      while(cin.get() != 10 && !cin.eof());
      xstack.push(hx);
      ystack.push(hy);
      sigstack.push(hsig);      
     
    }

  // we have them now in stacks, copy it to the array.
  // but first allocate space for these arrays (since we now know how large 
  // they should be):
  *ndata = sigstack.size();  
  
  *x = nr_vector<xtype>(1,*ndata);
  *y = nr_vector<floatt>(1,*ndata);
  *sig = nr_vector<floatt>(1,*ndata);
  
  int j = *ndata;
  while(!sigstack.empty())
    { 
      
      (*x)[j] = xstack.top();
      (*y)[j]   = ystack.top();	
      (*sig)[j] = sigstack.top();
      xstack.pop(); ystack.pop(); sigstack.pop();
      // cout << "x " << (*x)[j].x << "  " << (*x)[j].formC << " y  " << (*y)[j] << "  sig " << (*sig)[j] << endl;
      j--;

    }


  return;
}/* read */

static void write(xtype *x,floatt * y, floatt *sig, floatt *a, int * ia, void * c, floatt ** covar, int ndata , string * descr_of_a, int npar )
  {
    cout <<  "****************************************\n" ;
    cout <<  String << "\n\n"; // fitted function  
    
    int mfit = 0; // to determine the number of fitted parameters (and with it, the number of degrees of freedom)
    int i;
    for(i = 1; i <= npar; i++)
      {
	if (ia[i] != 0) mfit ++; 
	printf("%2d  %s = %11.7"FF" +- %11.7"FF"\n", 
	       i, (descr_of_a[i]).c_str(), a[i], sqrt(abs(covar[i][i])));
      } 
    // we compare the fit to the measured values:
    floatt * dyda= nr_vector<floatt>(1,npar); //
    floatt yc; // calculated y      
    
    cout << "\n   x       Qin    error    Qcom    rel. dev.\n\n";
    for(i=1; i <= ndata; i++)
      {      
	function(x[i], a, &yc, dyda,npar); 
	printf("%12.6"FF" %10.6"FF" +- %10.6"FF" %10.6"FF" %10.6"FF"\n",
	       x[i].x,  y[i],         sig[i],  yc,  ((y[i]-yc)/sig[i])); 
      }
    
  }/*write*/
 
 
}; // f2calc class

const string f2calc::String =  
"g(ar, b) =  a0 + a1 (log(ar) - b ? C : 0)"
              " + a2 (log(ar) - b ? C : 0)^2"
              "  + a3 (log(ar) - b ? C : 0)^3 "
              "  + a4 (log(ar) - b ? C : 0)^4 "
; 
