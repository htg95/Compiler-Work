#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <unistd.h>
#include <sys/time.h>

#define M 1024
double cos1[M][M+13];
double temp2d[M][M+23];
double block[M][M+43];
double sum2[M][M];

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

void init_array()
{
    int i, j;

    for (i=0; i<M; i++) {
        for (j=0; j<M; j++) {
            cos1[i][j] = (1+(i*j)%1024)/2.0;
            block[i][j] = (1+(i*j)%1024)/2.0;
        }
    }
}


void print_array()
{
    int i, j;

    for (i=0; i<M; i++) {
        for (j=0; j<M; j++) {
            fprintf(stdout, "%lf ", block[i][j]);
            if (j%80 == 79) fprintf(stdout, "\n");
        }
        fprintf(stdout, "\n");
    }
}

double rtclock()
{
    struct timezone Tzp;
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, &Tzp);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}
double t_start, t_end;

int main()
{
	int i, j, k, l, m, n, o, t;

	init_array();

#ifdef PERFCTR
	PERF_INIT; 
#endif

	IF_TIME(t_start = rtclock());








  int t1, t2, t3, t4, t5, t6, t7, t8, t9;

 register int lbv, ubv;

/* Start of CLooG code */
if (M >= 1) {
  for (t2=0;t2<=floord(M-1,32);t2++) {
    for (t3=0;t3<=floord(M-1,32);t3++) {
      for (t4=32*t2;t4<=min(M-1,32*t2+31);t4++) {
        lbv=32*t3;
        ubv=min(M-1,32*t3+31);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          sum2[t4][t5] = 0.0;;
          temp2d[t4][t5] = 0.0;;
        }
      }
    }
  }
  for (t2=0;t2<=floord(M-1,32);t2++) {
    for (t3=0;t3<=floord(M-1,32);t3++) {
      for (t5=0;t5<=floord(M-1,32);t5++) {
        for (t6=32*t2;t6<=min(M-1,32*t2+31);t6++) {
          for (t7=32*t3;t7<=min(M-1,32*t3+31);t7++) {
            for (t9=32*t5;t9<=min(M-1,32*t5+31);t9++) {
              temp2d[t7][t6] = temp2d[t7][t6] + block[t7][t9] * cos1[t6][t9];;
            }
          }
        }
      }
      for (t5=0;t5<=floord(M-1,32);t5++) {
        for (t6=32*t2;t6<=min(M-1,32*t2+31);t6++) {
          for (t7=32*t3;t7<=min(M-1,32*t3+31);t7++) {
            lbv=32*t5;
            ubv=min(M-1,32*t5+31);
#pragma ivdep
#pragma vector always
            for (t9=lbv;t9<=ubv;t9++) {
              sum2[t9][t6] = sum2[t9][t6] + cos1[t9][t7] * temp2d[t7][t6];;
            }
          }
        }
      }
    }
  }
  for (t2=0;t2<=floord(M-1,32);t2++) {
    for (t3=0;t3<=floord(M-1,32);t3++) {
      for (t4=32*t2;t4<=min(M-1,32*t2+31);t4++) {
        lbv=32*t3;
        ubv=min(M-1,32*t3+31);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          block[t4][t5] = (sum2[t4][t5]);;
        }
      }
    }
  }
}
/* End of CLooG code */

    IF_TIME(t_end = rtclock());
    IF_TIME(fprintf(stderr, "%0.6lfs\n", t_end - t_start));

#ifdef PERFCTR
    PERF_EXIT; 
#endif

#ifdef TEST
    print_array();
#endif
    return 0;
}
