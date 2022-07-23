

#include "cmdln.h"
#include "function.h"

#include "f2calc.h"

class qcalc : public functiontype
{
  
 public:
  static const string String;
  // struct xtype { floatt k; int l;};
  struct xtype { floatt k; int l; bool A;};
  
  // This is the function wich we're going to fit.

  // as a string
  //static const string String; // =  "q(k,l) = l^(2*yt-3) * (a0+ya1*(kc-k)*l^yt+b1*l^yi+b2*l^yj) + c0";  // not sure if this string is correct.
  //static const int npar;
  //static string descr_of_a[npar+1]; // well, one two many, we simply don't use descr_of_a[0]...
  // itself
  static void function (xtype x, floatt a[], floatt * y, floatt dyda[], int npar)
    {            
      
      floatt wk;
      //  calculate q(k,l) and its first derivatives
      if(x.A)
	{
	  wk = ((a[3]-x.k)*(1.0+a[17]*(a[3]-x.k)))*pow(x.l,a[19]); 
	  
	  *y =   a[5]*pow(x.l,a[18]) 
	    + a[7]*pow(x.l,a[20]) 
	    + a[1] 
	    + wk* (a[9]+wk*(a[10]+wk*(a[11]+wk*a[12])));
	}
      else
	{
	  wk = ((a[4]-x.k)*(1.0+a[17]*(a[4]-x.k)))*pow(x.l,a[19]); 
	  
	  *y =   a[6]*pow(x.l,a[18]) 
	    + a[8]*pow(x.l,a[20]) 
	    + a[2] 
	    + wk* (a[13]+wk*(a[14]+wk*(a[15]+wk*a[16])));
	}

      // first put every derivate zero, and then we only make unzero the ones needed:
      for(int i = 1; i<=20; i++) { dyda[i] = 0; }

      if(x.A)
	{
	  dyda[1] = 1.0; 
	  dyda[5] = pow(x.l,a[18]); 
	  dyda[9] = wk;
	  dyda[10] = wk*wk;
	  dyda[11] = dyda[10]*wk;
	  dyda[12] = dyda[11]*wk;
	  dyda[3] = pow(x.l,a[19])* (1.0 + 2.0 *a[17]*(a[3]-x.k))
	    * ( a[9] + wk*(2*a[10] + wk * (3*a[11]+wk*4*a[12])));
	  dyda[17] = pow(x.l,a[19]) * 
	    ( sqr(a[3]-x.k) * (a[9]+wk*(2*a[10]+wk*(3*a[11]+wk*4*a[12]))));
	  dyda[7] = pow(x.l,a[20]); 
	  dyda[18]= a[5] * pow(x.l,a[18]) * log((float)x.l); 
	  dyda[19]= wk * log((float)x.l);
	  dyda[20]= a[7] * pow(x.l,a[20]) * log((float)x.l); 	  
	}
      else
	{
	  cout << "hoi \n";
	  dyda[2] = 1.0; 
	  dyda[6] = pow(x.l,a[18]); 
	  dyda[13] = wk;
	  dyda[14] = wk*wk;
	  dyda[15] = dyda[14]*wk;
	  dyda[16] = dyda[15]*wk;
	  dyda[4] = pow(x.l,a[19])* (1.0 + 2.0 *a[17]*(a[4]-x.k))
	    * ( a[13] + wk*(2*a[14] + wk * (3*a[15]+wk*4*a[16])));
	  dyda[17] = pow(x.l,a[19]) * 
	    ( sqr(a[4]-x.k) * (a[13]+wk*(2*a[14]+wk*(3*a[15]+wk*4*a[16]))));
	  dyda[8] = pow(x.l,a[20]); 
	  dyda[18]= a[6] * pow(x.l,a[18]) * log((float)x.l); 
	  dyda[19]= wk * log((float)x.l);
	  dyda[20]= a[8] * pow(x.l,a[20]) * log((float)x.l); 	  
	}
    }
  
  static void init(string * sa, floatt * a, int * ia, void * c)
  //, floatt * Kc, floatt yt, bool fitKc)
    {
      floatt yi = -0.83;//((c_q*)c)->yi;      
      //cout << "yi " << yi << endl;
      // name        (initial) values    fit yes/no
      sa[1] = "Qca";  a[1] = 0.6235;           ia[1] = true; 
      sa[2] = "Qci";  a[2] = 0.6235;           ia[2] = true; 
      sa[3] = "Kca";  a[3] = ((c_q*)c)->Kca;   ia[3] = ((c_q*)c)->fitKc;
      sa[4] = "Kci";  a[4] = ((c_q*)c)->Kci;   ia[4] = ((c_q*)c)->fitKc;
      sa[5] = "p1a";  a[5] = ((c_q*)c)->p1a;   ia[5] = true;
      sa[6] = "p1i";  a[6] = ((c_q*)c)->p1i;   ia[6] = true;
      sa[7] = "p2a";  a[7] = ((c_q*)c)->p2a;   ia[7] = true;
      sa[8] = "p2i";  a[8] = ((c_q*)c)->p2i;   ia[8] = true;
      sa[9] = "a1a";  a[9] = ((c_q*)c)->a1a;   ia[9] = ((c_q*)c)->fita1;
      sa[10]= "a2a";  a[10] = ((c_q*)c)->a2a;   ia[10] = ((c_q*)c)->fita2;
      sa[11]= "a3a";  a[11] = ((c_q*)c)->a3a;   ia[11] = ((c_q*)c)->fita3;
      sa[12]= "a4a";  a[12] = ((c_q*)c)->a4a;   ia[12] = ((c_q*)c)->fita4;
      sa[13]= "a1i";  a[13] = ((c_q*)c)->a1i;   ia[13] = ((c_q*)c)->fita1;
      sa[14]= "a2i";  a[14] = ((c_q*)c)->a2i;   ia[14] = ((c_q*)c)->fita2;
      sa[15]= "a3i";  a[15] = ((c_q*)c)->a3i;   ia[15] = ((c_q*)c)->fita3;
      sa[16]= "a4i";  a[16] = ((c_q*)c)->a4i;   ia[16] = ((c_q*)c)->fita4;
      sa[17]= "nt";   a[17] = ((c_q*)c)->nt;    ia[17] = ((c_q*)c)->fitnt; 
      sa[18]= "yi";   a[18] = yi;               ia[18] = false;
      sa[19]= "yt";   a[19] = ((c_q*)c)->yt;    ia[19] = false;
      sa[20]= "y2";   a[20] = yi+yi;            ia[20] = false;
                      a[20] = -1.964;

    }

static void read(xtype ** x, floatt ** y, floatt ** sig, int * ndata, void * c)

  //          int minsystemsize, floatt sccr, floatt Kc, float yt, floatt deltaK)
  /*
    Reads the data from standard input. Firstly tempory in stacks, and then copies it to arrays 
   */
{
  // help variables 
  stack<xtype>  xstack;
  stack<floatt> ystack;
  stack<floatt> sigstack;
  xtype hx;
  floatt hy;
  floatt hsig;
  floatt wkc;
  int minsystemsize = ((c_q *)c)->minsystemsize;
  floatt sccr       = ((c_q *)c)->sccr; 
  floatt Kc         = ((c_q *)c)->Kca;
  float yt          = ((c_q *)c)->yt;
  floatt deltaK     = ((c_q *)c)->deltaK;
  
  hx.A = ((c_q*)c)->anisotropic;

  char achar;
  
  // read in stacks: 
  while(!cin.eof())
    {
      // we ignore lines beginning with # (to make commence possible)     
      cin >> achar;      
      if(achar== '#'){ while(cin.get() != 10 && !cin.eof()); continue;}	
      
      // if a line starts with 'C' then ignore rest of line and switch 'anisotropic'.      
      if(achar== 'C')
	{
	  while(cin.get() != 10 && !cin.eof());
	  hx.A = !hx.A;
	  Kc = hx.A ? ((c_q *)c)->Kca : ((c_q *)c)->Kci;
	  printf("switched \n");
	  continue;
	}	
     
      cin.putback(achar);      

      cin >> hx.l >>  hy >> hsig >> hx.k; 
      if(cin.eof()) break;
      // ignore rest of line      
      while(cin.get() != 10 && !cin.eof());
      
      wkc = pow(hx.l,yt); 
      if(hx.l < minsystemsize) continue; // ignore lines with too small mininum system size      
      if(abs(hx.k - Kc)*wkc > sccr) 
	 {
	   printf("# rejected (sccr)  %d  %"FF"  %"FF"  %"FF"\n",hx.l, hy,  hsig, hx.k); 
	   continue;
	 }
      if(abs(hx.k - Kc) > deltaK) 
	{
	  printf("# rejected (%"FF")  %d  %"FF"  %"FF"  %"FF"\n",deltaK,hx.l, hy,  hsig, hx.k); 
	  continue;           
	}
      xstack.push(hx);
      ystack.push(hy);
      sigstack.push(hsig);      
      printf("accepted %d  %"FF"  %"FF"  %"FF"\n",hx.l, hy,  hsig, hx.k); 
     
    }

  // we have them now in stacks, copy it to the array.
  // but first allocate space for these arrays (since we now know how large they should be):
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
      j--;
    }

  return;
}/* read */
 
 static void write(xtype *x,floatt * y, floatt *sig, floatt *a, int * ia, void * c, floatt ** covar, int ndata, string * descr_of_a, int npar)
   {
     int minsystemsize = ((c_q *)c)->minsystemsize;
     floatt sccr       = ((c_q *)c)->sccr; 
     floatt Kc         = ((c_q *)c)->Kca;
     float yt          = ((c_q *)c)->yt;
     floatt deltaK     = ((c_q *)c)->deltaK;
     // ready, output the results to standard output.
      cout <<  "****************************************\n" ;
      cout <<  String << "\n\n"; // fitted function
      
      //int mfit = 0; // to determine the number of fitted parameters (and with it, the number of degrees of freedom)
      // determining of mfit can be done in an apart, general function
      for(int i = 1; i <= npar; i++)
	{
	  //	  if (ia[i] != 0) mfit ++; 
	  printf("%2d  %s = %11.7"FF" +- %11.7"FF"\n", i, (descr_of_a[i]).c_str(), a[i], sqrt(abs(covar[i][i])));
	  // well it would of course be nicer to use 'cout' but it's cumbersome also, I would say...
	} 
      cout
      << "\nscaling-width crit. "<< sccr   
	   << endl;
      
      // we compare the fit to the measured values:
      floatt * dyda= nr_vector<floatt>(1,npar); // needed to call qcalc
      floatt yc; // calculated y      
      cout << "\n   l       c1       input       error    computed  rel. dev.\n\n";
      for(int i=1; i <= ndata; i++)
	{      
	  function(x[i], a, &yc, dyda,npar); 
	  printf("%4d %12.6"FF" %10.6"FF" +- %10.6"FF" %10.6"FF" %10.6"FF"\n",
		 x[i].l,x[i].k,y[i],sig[i],yc,((y[i]-yc)/sig[i])); 
	}
      
      

   }

}; // qcalc class



const string qcalc::String  =  "q(k,l) = l^(2*yt-3) * (a0+ya1*(kc-k)*l^yt+b1*l^yi+b2*l^yj) + c0";  // not sure if this string is correct.
