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
//#include <sys/time.h>
#include<malloc.h>
#define M 1024
#define N 1024
#define K 1024
#define alpha 1
#define beta 1

// #pragma declarations
// double A[M][K];
// double B[K][N];
// double C[M][N];
// #pragma enddeclarations

// #ifdef PERFCTR
// #include "papiStdEventDefs.h"
// #include <papi.h>
// #include "papi_defs.h"
// #endif

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void init_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // A[i][j] = (i + j);
            // B[i][j] = (double)(i*j);
            // C[i][j] = 0.0;
        // }
    // }
// }

// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // fprintf(stderr, "%lf ", C[i][j]);
            // if (j%80 == 79) fprintf(stderr, "\n");
        // }
        // fprintf(stderr, "\n");
    // }
// }

// double rtclock()
// {
    // struct timezone Tzp;
    // struct timeval Tp;
    // int stat;
    // stat = gettimeofday (&Tp, &Tzp);
    // if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    // return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
// }
// double t_start, t_end;

int main()
{
	double **A;
    double **B;
    double **C;		
    int i, j, k;
	int size=(N)*(N)*sizeof(double);
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
    // init_array();

// #ifdef PERFCTR
    // PERF_INIT; 
// #endif

    //IF_TIME(t_start = rtclock());
	
	A=(double **) malloc(sizeof(double *)*(N));
	A[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	A[i]=(*A + N*i);
	}

	B=(double **) malloc(sizeof(double *)*(N));
	B[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	B[i]=(*B + N*i);
	}
	C=(double **) malloc(sizeof(double *)*(N));
	C[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	C[i]=(*C + N*i);
	}
 
printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*A,*B,&A[0][0],&B[0][0]);

  
  int t1, t2, t3, t4, t5, t6;
 register int lbv, ubv;
/* Start of CLooG code */
if ((N >= 1) && (N >= 1) && (N >= 1)) {
  for (t1=0;t1<=floord(N-1,8);t1++) {
    for (t2=0;t2<=floord(N-1,8);t2++) {
      for (t3=0;t3<=floord(N-1,8);t3++) {
        for (t4=8*t1;t4<=min(N-1,8*t1+7);t4++) {
          for (t5=8*t3;t5<=min(N-1,8*t3+7);t5++) {
            lbv=8*t2;
            ubv=min(N-1,8*t2+7);
#pragma ivdep
#pragma vector always
            for (t6=lbv;t6<=ubv;t6++) {
              C[t4][t6] = beta*C[t4][t6] + alpha*A[t4][t5] * B[t5][t6];
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

// #ifdef PERFCTR
    // PERF_EXIT; 
// #endif

  // if (fopen(".test", "r")) {
// #ifdef MPI
      // if (my_rank == 0) {
          // print_array();
      // }
// #else
          // print_array();
// #endif
  // }

  return 0;
}
