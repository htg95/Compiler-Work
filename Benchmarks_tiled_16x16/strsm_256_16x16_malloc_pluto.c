#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <sys/time.h>
#include <unistd.h>
#include <malloc.h>
// #include <sys/time.h>

#define NMAX 256

//static double a[NMAX][NMAX], b[NMAX][NMAX];

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

// #define TIME 1

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif




int main()
{
	
	double **a;
	double **b;
	int size=(NMAX)*(NMAX)*sizeof(double);
    double t_start, t_end;
    long N=NMAX;
    // int i,j;
	
    // IF_TIME(t_start = rtclock());
    int i,j,k;

  int t1, t2, t3, t4, t5, t6, t7;
 register int lbv, ubv;
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
 
 printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*a,*b,&a[0][0],&b[0][0]);

 
 void init_array()
{
    int i, j;

    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX; j++) {
            b[i][j] = i*j*0.3+1;
            a[i][j] = i+j+1;
        }
    }
}
 
 
 
/* Start of CLooG code */
if (N >= 2) {
  for (t1=0;t1<=floord(N-1,16);t1++) {
    for (t2=0;t2<=floord(N-2,16);t2++) {
      for (t3=t2;t3<=floord(N-1,16);t3++) {
        if (t2 == t3-1) {
          for (t4=16*t1;t4<=min(N-1,16*t1+15);t4++) {
            for (t5=16*t2;t5<=16*t2+6;t5++) {
              for (t6=16*t2+16;t6<=min(N-1,16*t2+15);t6++) {
                b[t4][t6] -= a[t5][t6] * b[t4][t5];;
              }
            }
            b[t4][(16*t2+15)] /= a[(16*t2+15)][(16*t2+15)];;
            for (t6=16*t2+16;t6<=min(N-1,16*t2+15);t6++) {
              b[t4][t6] -= a[(16*t2+15)][t6] * b[t4][(16*t2+15)];;
            }
          }
        }
        if (t2 == t3) {
          for (t4=16*t1;t4<=min(N-1,16*t1+15);t4++) {
            for (t5=16*t2;t5<=min(N-2,16*t2+6);t5++) {
              b[t4][t5] /= a[t5][t5];;
              for (t6=t5+1;t6<=min(N-1,16*t2+15);t6++) {
                b[t4][t6] -= a[t5][t6] * b[t4][t5];;
              }
            }
          }
        }
        if (t2 <= t3-2) {
          for (t4=16*t1;t4<=min(N-1,16*t1+15);t4++) {
            for (t5=16*t2;t5<=16*t2+15;t5++) {
              for (t6=16*t3;t6<=min(N-1,16*t3+15);t6++) {
                b[t4][t6] -= a[t5][t6] * b[t4][t5];;
              }
            }
          }
        }
      }
    }
  }
}
    // IF_TIME(t_end = rtclock());

    // IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

    // if (fopen(".test", "r")) {
        // for (i = 0; i < N; i++) {
            // for (j = 0; j < N; j++) {
                // fprintf(stderr, "%lf ",  b[i][j]);
            // }
            // fprintf(stderr, "\n");
        // }
    // }

    return 0;
}
