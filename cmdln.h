/*  automatic code produced by gencom 0.54 on Wed May 12 14:26:25 1999

    inputfile: <cmdln.cmdl>
 */

#ifndef __cmdln_cmdl__
#define __cmdln_cmdl__
#include <stdio.h>

class c_q
{
 char * info;
 public:
  c_q(int = 0, char * argv[] = NULL, char * _info = NULL);

  friend ostream& operator<<(ostream&, const c_q&);
  double  Kca;
  double  Kci;
  double  a1a;
  double  a2a;
  double  a3a;
  double  a4a;
  double  a1i;
  double  a2i;
  double  a3i;
  double  a4i;
  double  p1a;
  double  p1i;
  double  p2a;
  double  p2i;
  bool  fita1;
  bool  fita2;
  bool  fita3;
  bool  fita4;
  bool  fitKc;
  bool  fitnt;
  double  yt;
  double  yi;
  double  nt;
  int  minsystemsize;
  double  sccr;
  double  deltaK;
  double  conv;
  bool  anisotropic;
};

c_q::c_q(int argc, char *argv[], char * _info)
{
   info = _info;
  char * gc_string;
   Kca = 3.0443904;
   Kci = 0.2216546;
   a1a = -0.653;
   a2a = 0.325;
   a3a = 0.715;
   a4a = 0;
   a1i = -0.653;
   a2i = 0.325;
   a3i = 0.715;
   a4i = 0;
   p1a = -.0226;
   p1i = -.0226;
   p2a = 0;
   p2i = 0;
   gc_string = "+";
   fita1 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fita2 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fita3 = gc_string[0] == '+' ? true : false;
   gc_string = "-";
   fita4 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fitKc = gc_string[0] == '+' ? true : false;
   gc_string = "-";
   fitnt = gc_string[0] == '+' ? true : false;
   yt = 1.585;
   yi = -0.81;
   nt = 0;
   minsystemsize = 4;
   sccr = 3.0;
   deltaK = 0.25;
   conv = 0.2e-7;
   gc_string = "+";
   anisotropic = gc_string[0] == '+' ? true : false;
  for(int i = 2; i<argc; i++)
     {
      int recognized = 0;
      if(!memcmp("Kca",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &Kca); recognized++;}
      if(!memcmp("Kci",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &Kci); recognized++;}
      if(!memcmp("a1a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a1a); recognized++;}
      if(!memcmp("a2a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a2a); recognized++;}
      if(!memcmp("a3a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a3a); recognized++;}
      if(!memcmp("a4a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a4a); recognized++;}
      if(!memcmp("a1i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a1i); recognized++;}
      if(!memcmp("a2i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a2i); recognized++;}
      if(!memcmp("a3i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a3i); recognized++;}
      if(!memcmp("a4i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &a4i); recognized++;}
      if(!memcmp("p1a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &p1a); recognized++;}
      if(!memcmp("p1i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &p1i); recognized++;}
      if(!memcmp("p2a",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &p2a); recognized++;}
      if(!memcmp("p2i",argv[i], 3)){ sscanf(argv[i] + 3, "%lf", &p2i); recognized++;}
      if(!memcmp("fita1",argv[i], 5)){ gc_string = argv[i] + 5; fita1 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita2",argv[i], 5)){ gc_string = argv[i] + 5; fita2 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita3",argv[i], 5)){ gc_string = argv[i] + 5; fita3 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita4",argv[i], 5)){ gc_string = argv[i] + 5; fita4 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fitKc",argv[i], 5)){ gc_string = argv[i] + 5; fitKc = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fitnt",argv[i], 5)){ gc_string = argv[i] + 5; fitnt = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("yt",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &yt); recognized++;}
      if(!memcmp("yi",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &yi); recognized++;}
      if(!memcmp("nt",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &nt); recognized++;}
      if(!memcmp("m",argv[i], 1)){ sscanf(argv[i] + 1, "%d", &minsystemsize); recognized++;}
      if(!memcmp("s",argv[i], 1)){ sscanf(argv[i] + 1, "%lf", &sccr); recognized++;}
      if(!memcmp("d",argv[i], 1)){ sscanf(argv[i] + 1, "%lf", &deltaK); recognized++;}
      if(!memcmp("conv",argv[i], 4)){ sscanf(argv[i] + 4, "%lf", &conv); recognized++;}
      if(!memcmp("anisotropic",argv[i], 11)){ gc_string = argv[i] + 11; anisotropic = gc_string[0] == '+' ? true : false; recognized++;}
      if(argv[i][0] == 'h')
        {
        recognized++;
        if(info) printf("%s\n",info);
        printf("use:\n    %s [options] \n", argv[0]);
        printf("options:\n"); 
        printf(" Kca???         :(3.0443904) specify Kc\n");
        printf(" Kci???         :(0.2216546) specify Kc\n");
        printf(" a1a???         :(-0.653) -undocumented-\n");
        printf(" a2a???         :(0.325) -undocumented-\n");
        printf(" a3a???         :(0.715) -undocumented-\n");
        printf(" a4a???         :(0) -undocumented-\n");
        printf(" a1i???         :(-0.653) -undocumented-\n");
        printf(" a2i???         :(0.325) -undocumented-\n");
        printf(" a3i???         :(0.715) -undocumented-\n");
        printf(" a4i???         :(0) -undocumented-\n");
        printf(" p1a???         :(-.0226) -undocumented-\n");
        printf(" p1i???         :(-.0226) -undocumented-\n");
        printf(" p2a???         :(0) -undocumented-\n");
        printf(" p2i???         :(0) -undocumented-\n");
        printf(" fita1???       :(+) -undocumented-\n");
        printf(" fita2???       :(+) -undocumented-\n");
        printf(" fita3???       :(+) -undocumented-\n");
        printf(" fita4???       :(-) -undocumented-\n");
        printf(" fitKc???       :(+) if Kc should be fit\n");
        printf(" fitnt???       :(-) -undocumented-\n");
        printf(" yt???          :(1.585) specify yt\n");
        printf(" yi???          :(-0.81) specify yi\n");
        printf(" nt???          :(0) -undocumented-\n");
        printf(" m???           :(4) specify a minimum systemsize. Bigger systems will be ignored\n");
        printf(" s???           :(3.0) specify 'scaling width criterium'\n");
        printf(" d???           :(0.25) how much K may differ from Kc\n");
        printf(" conv???        :(0.2e-7) halting criteria\n");
        printf(" anisotropic??? :(+) wether the variables for anistropic or isotropic model should be used \n"
               "                  this can be switched by sending C\n");
        exit(0);
        }
      if(!recognized) { printf("Unrecognized commandline option %s (try 'h')\n", argv[i]);exit(1);}
      if(recognized > 1) { printf("**Dubious commandline option %s (this is a bug in sourcefile cmdln.cmdl)**\n", argv[i]);exit(1);}
     }
}

 ostream& operator<<(ostream& os, const c_q& s)
   {
    os
    << "Kca = " << s.Kca << endl
    << "Kci = " << s.Kci << endl
    << "a1a = " << s.a1a << endl
    << "a2a = " << s.a2a << endl
    << "a3a = " << s.a3a << endl
    << "a4a = " << s.a4a << endl
    << "a1i = " << s.a1i << endl
    << "a2i = " << s.a2i << endl
    << "a3i = " << s.a3i << endl
    << "a4i = " << s.a4i << endl
    << "p1a = " << s.p1a << endl
    << "p1i = " << s.p1i << endl
    << "p2a = " << s.p2a << endl
    << "p2i = " << s.p2i << endl
    << "fita1 = " << s.fita1 << endl
    << "fita2 = " << s.fita2 << endl
    << "fita3 = " << s.fita3 << endl
    << "fita4 = " << s.fita4 << endl
    << "fitKc = " << s.fitKc << endl
    << "fitnt = " << s.fitnt << endl
    << "yt = " << s.yt << endl
    << "yi = " << s.yi << endl
    << "nt = " << s.nt << endl
    << "minsystemsize = " << s.minsystemsize << endl
    << "sccr = " << s.sccr << endl
    << "deltaK = " << s.deltaK << endl
    << "conv = " << s.conv << endl
    << "anisotropic = " << s.anisotropic << endl
    ;
    return os;
   }
#include <stdio.h>

class c_f2
{
 char * info;
 public:
  c_f2(int = 0, char * argv[] = NULL, char * _info = NULL);

  friend ostream& operator<<(ostream&, const c_f2&);
  double  conv;
  double  a0;
  double  a1;
  double  a2;
  double  a3;
  double  a4;
  double  C;
  bool  fita0;
  bool  fita1;
  bool  fita2;
  bool  fita3;
  bool  fita4;
  bool  fitC;
  bool  formC;
};

c_f2::c_f2(int argc, char *argv[], char * _info)
{
   info = _info;
  char * gc_string;
   conv = 0.2e-7;
   a0 = 0.6236;
   a1 = 0;
   a2 = -0.09;
   a3 = 0;
   a4 = 0;
   C = -0.11;
   gc_string = "+";
   fita0 = gc_string[0] == '+' ? true : false;
   gc_string = "-";
   fita1 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fita2 = gc_string[0] == '+' ? true : false;
   gc_string = "-";
   fita3 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fita4 = gc_string[0] == '+' ? true : false;
   gc_string = "+";
   fitC = gc_string[0] == '+' ? true : false;
   gc_string = "-";
   formC = gc_string[0] == '+' ? true : false;
  for(int i = 2; i<argc; i++)
     {
      int recognized = 0;
      if(!memcmp("conv",argv[i], 4)){ sscanf(argv[i] + 4, "%lf", &conv); recognized++;}
      if(!memcmp("a0",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &a0); recognized++;}
      if(!memcmp("a1",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &a1); recognized++;}
      if(!memcmp("a2",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &a2); recognized++;}
      if(!memcmp("a3",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &a3); recognized++;}
      if(!memcmp("a4",argv[i], 2)){ sscanf(argv[i] + 2, "%lf", &a4); recognized++;}
      if(!memcmp("C",argv[i], 1)){ sscanf(argv[i] + 1, "%lf", &C); recognized++;}
      if(!memcmp("fita0",argv[i], 5)){ gc_string = argv[i] + 5; fita0 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita1",argv[i], 5)){ gc_string = argv[i] + 5; fita1 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita2",argv[i], 5)){ gc_string = argv[i] + 5; fita2 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita3",argv[i], 5)){ gc_string = argv[i] + 5; fita3 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fita4",argv[i], 5)){ gc_string = argv[i] + 5; fita4 = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("fitC",argv[i], 4)){ gc_string = argv[i] + 4; fitC = gc_string[0] == '+' ? true : false; recognized++;}
      if(!memcmp("formC",argv[i], 5)){ gc_string = argv[i] + 5; formC = gc_string[0] == '+' ? true : false; recognized++;}
      if(argv[i][0] == 'h')
        {
        recognized++;
        if(info) printf("%s\n",info);
        printf("use:\n    %s [options] \n", argv[0]);
        printf("options:\n"); 
        printf(" conv???  :(0.2e-7) halting criteria\n");
        printf(" a0???    :(0.6236) starting value for a0\n");
        printf(" a1???    :(0) starting value for a1\n");
        printf(" a2???    :(-0.09) starting value for a2\n");
        printf(" a3???    :(0) -undocumented-\n");
        printf(" a4???    :(0) -undocumented-\n");
        printf(" C???     :(-0.11) -undocumented-\n");
        printf(" fita0??? :(+) wether a0 should be fit\n");
        printf(" fita1??? :(-) wether a1 should be fit\n");
        printf(" fita2??? :(+) wether a2 should be fit\n");
        printf(" fita3??? :(-) wether a3 should be fit\n");
        printf(" fita4??? :(+) wether a4 should be fit\n");
        printf(" fitC???  :(+) wether C should be fit\n");
        printf(" formC??? :(-) wether C in formula, this can be switched by sending C\n");
        exit(0);
        }
      if(!recognized) { printf("Unrecognized commandline option %s (try 'h')\n", argv[i]);exit(1);}
      if(recognized > 1) { printf("**Dubious commandline option %s (this is a bug in sourcefile cmdln.cmdl)**\n", argv[i]);exit(1);}
     }
}

 ostream& operator<<(ostream& os, const c_f2& s)
   {
    os
    << "conv = " << s.conv << endl
    << "a0 = " << s.a0 << endl
    << "a1 = " << s.a1 << endl
    << "a2 = " << s.a2 << endl
    << "a3 = " << s.a3 << endl
    << "a4 = " << s.a4 << endl
    << "C = " << s.C << endl
    << "fita0 = " << s.fita0 << endl
    << "fita1 = " << s.fita1 << endl
    << "fita2 = " << s.fita2 << endl
    << "fita3 = " << s.fita3 << endl
    << "fita4 = " << s.fita4 << endl
    << "fitC = " << s.fitC << endl
    << "formC = " << s.formC << endl
    ;
    return os;
   }
class c_cmdln
{
 static  char * info;
 public:
  static int read(int argc, char * argv[], char * _info = NULL)
     { 
        info = _info;
        if(argc == 1) return 0;
        if(!strcmp("g", argv[1])) return c_f2;
        if(!strcmp("q", argv[1])) return c_q;
        if(argv[1][0] == 'h')
          {
           if(info) printf("%s\n",info);
          }
        return -1;
     }

  friend ostream& operator<<(ostream&, const c_cmdln&);
  enum {c_q,c_f2};
};
char * c_cmdln::info = NULL;
#endif // __cmdln_cmdl__
