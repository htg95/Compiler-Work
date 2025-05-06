#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define NMAX 256

// #pragma declarations
// double a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];
// #pragma enddeclarations

// #define TIME 1

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// double rtclock()
// {
    // struct timezone Tzp;
    // struct timeval Tp;
    // int stat;
    // stat = gettimeofday (&Tp, &Tzp);
    // if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    // return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
// }



int main()
{
  double **a;
  double **b;
  double **c;
  double t_start, t_end;
  int i,j, k;
int size=(NMAX)*(NMAX)*sizeof(double);
int _4_zeros=1<<28;
printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);


a=(double **) malloc(sizeof(double *)*(NMAX));
a[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
a[i]=(*a + NMAX*i);
}

b=(double **) malloc(sizeof(double *)*(NMAX));
b[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
b[i]=(*b + NMAX*i);
}



  /* for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      b[i][j] = i+j;
      a[i][j] = i*j*0.5;
    }
  } */

  //IF_TIME(t_start = rtclock());
 c=(double **) malloc(sizeof(double *)*(NMAX));
c[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
c[i]=(*c + (NMAX)*i);
}
 
printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*a,*b,&a[0][0],&b[0][0]);


  int t1, t2, t3, t4, t5, t6;

 register int lbv, ubv;


/* Start of CLooG code */
if (NMAX >= 2) {
  for (t1=0;t1<=floord(NMAX-1,32);t1++) {
    for (t2=0;t2<=floord(NMAX-1,32);t2++) {
      for (t3=0;t3<=min(floord(NMAX-2,32),t2);t3++) {
        for (t4=32*t1;t4<=min(NMAX-1,32*t1+31);t4++) {
          for (t5=max(32*t2,32*t3+1);t5<=min(NMAX-1,32*t2+31);t5++) {
            lbv=32*t3;
            ubv=min(32*t3+31,t5-1);
#pragma ivdep
#pragma vector always
            for (t6=lbv;t6<=ubv;t6++) {
              b[t4][t6] += a[t5][t6] * b[t4][t5];;
            }
          }
        }
      }
    }
  }
}
/* End of CLooG code */


  // IF_TIME(t_end = rtclock());
  // IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  // if (fopen(".test", "r")) {
// #ifdef MPI
      // if (my_rank == 0) {
// #endif
    // for (i = 0; i < NMAX; i++) {
      // for (j = 0; j < NMAX; j++) {
        // fprintf(stderr, "%lf ",  b[i][j]);
      // }
    // }
    // fprintf(stderr, "\n");
// #ifdef MPI
      // }
// #endif
  // }

  return 0;
}
