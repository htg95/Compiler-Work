#include <omp.h>
#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <sys/time.h>
#include <malloc.h>
#define NMAX 1024

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
  long double **a;
  long double **b;
  long double **c;		
  int i,j, k;
  long double t_start, t_end;
int size=(NMAX)*(NMAX)*sizeof(long double);
int _4_zeros=1<<28;
printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);


a=(long double **) malloc(sizeof(long double *)*(NMAX));
a[0]=(long double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
a[i]=(*a + NMAX*i);
}

b=(long double **) malloc(sizeof(long double *)*(NMAX));
b[0]=(long double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
b[i]=(*b + NMAX*i);
}
 c=(long double **) malloc(sizeof(long double *)*(NMAX));
c[0]=(long double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
c[i]=(*c + (NMAX)*i);
}
 
printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*a,*b,&a[0][0],&b[0][0]);



  /* for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      c[i][j] = 0.0;
      a[i][j] = b[i][j] = i*j*0.5 / NMAX;
    }
  }
 */
  //IF_TIME(t_start = rtclock());




  int lb, ub, lbp, ubp, lb2, ub2;
  int t1, t2, t3, t4, t5, t6, t7;

 register int lbv, ubv;

/* Start of CLooG code */
if (NMAX >= 1) {
  if (NMAX >= 3) {
    lbp=0;
    ubp=floord(NMAX-1,32);
#pragma omp parallel for private(lbv,ubv,t3,t4,t5,t6,t7)
    for (t2=lbp;t2<=ubp;t2++) {
      for (t3=0;t3<=floord(NMAX-1,32);t3++) {
        for (t4=0;t4<=min(floord(NMAX-3,32),t3);t4++) {
          for (t5=32*t2;t5<=min(NMAX-1,32*t2+31);t5++) {
            for (t6=max(32*t3,32*t4+2);t6<=min(NMAX-1,32*t3+31);t6++) {
              for (t7=32*t4;t7<=min(32*t4+31,t6-2);t7++) {
                c[t5][t6] += a[t6][t6] * b[t5][t6];;
              }
            }
          }
        }
      }
    }
  }
  lbp=0;
  ubp=floord(NMAX-1,32);
#pragma omp parallel for private(lbv,ubv,t3,t4,t5,t6,t7)
  for (t2=lbp;t2<=ubp;t2++) {
    for (t3=0;t3<=floord(NMAX-1,32);t3++) {
      for (t4=32*t2;t4<=min(NMAX-1,32*t2+31);t4++) {
        lbv=32*t3;
        ubv=min(NMAX-1,32*t3+31);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          c[t4][t5] += a[t5][t5] * b[t4][t5];;
        }
      }
    }
  }
  if (NMAX >= 3) {
    lbp=0;
    ubp=floord(NMAX-1,32);
#pragma omp parallel for private(lbv,ubv,t3,t4,t5,t6,t7)
    for (t2=lbp;t2<=ubp;t2++) {
      for (t3=0;t3<=floord(NMAX-3,32);t3++) {
        for (t4=t3;t4<=floord(NMAX-1,32);t4++) {
          for (t5=32*t2;t5<=min(NMAX-1,32*t2+31);t5++) {
            for (t6=max(32*t4,32*t3+2);t6<=min(NMAX-1,32*t4+31);t6++) {
              lbv=32*t3;
              ubv=min(32*t3+31,t6-2);
#pragma ivdep
#pragma vector always
              for (t7=lbv;t7<=ubv;t7++) {
                c[t5][t7] += a[t6][t7] * b[t5][t6];;
              }
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

  // if (fopen(".test", "r"))  {
// #ifdef MPI
      // if (my_rank == 0) {
// #endif
          // for (i = 0; i < NMAX; i++) {
              // for (j = 0; j < NMAX; j++) {
                  // fprintf(stderr, "%lf ", c[i][j]);
              // }
              // fprintf(stderr, "\n");
          // }
// #ifdef MPI
      // }
// #endif
  // }

  return 0;
}
