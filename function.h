//  -*-c++-*-
#ifndef ___function_h__
#define ___function_h__


// Used floating point type is 'floatt'. Change the following two lines if you want to change it:
typedef double floatt;
#define FF "lf"        //floatt formatspecifier, in case you want to use printf...

// extra mathematical functions:
//template<class T> T sqr(T x) { return x*x; }
//template<class T> T abs(T x) { return x>=0 ? x : -x; }

class functiontype
{
 public:
  struct xtype;
  //  static const string String;
  static void function(xtype x, floatt a[], floatt * y, floatt dyda[], int npar) ;
  static void init(string * sa, floatt * a, int * ia);
  static void read(xtype ** x, floatt ** y, floatt ** sig, int * ndata);
  static void write(xtype *x,floatt * y, floatt *sig, floatt *a, int * ia, void * c, floatt ** covar, int ndata, int npar )
    {
    };
  
};

#endif // ___function_h__
