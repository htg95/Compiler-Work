#include <math.h>
#define ceild(n,d)  ceil(((long double)(n))/((long double)(d)))
#define floord(n,d) floor(((long double)(n))/((long double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
//#include <sys/time.h>
#include <malloc.h>
#include <assert.h>

#define N 1024
#define T 200

// #pragma declarations
// long double a[N][N];
// #pragma enddeclarations

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
            // a[i][j] = i*i+j*j;
        // }
    // }
// }


// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // fprintf(stderr, "%0.2lf ", a[i][j]);
            // if (j%80 == 20) fprintf(stderr, "\n");
        // }
    // }
    // fprintf(stderr, "\n");
// }

// long double rtclock()
// {
    // struct timezone Tzp;
    // struct timeval Tp;
    // int stat;
    // stat = gettimeofday (&Tp, &Tzp);
    // if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    // return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
// }

// #define __PLACE_TO_INSERT_FORWARD_DECLARATIONS

int main()
{	
	long double **a;
    int i, j, k, t;

    long double t_start, t_end;
	int   size=(N)*(N)*sizeof(long double);
    // init_array() ;
	int _4_zeros=1<<28;
  printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);  
// #ifdef PERFCTR
    // PERF_INIT; 
// #endif
  a=(long double **) malloc(sizeof(long double *)*(N));
  a[0]=(long double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	a[i]=(*a + N*i);
	}
    // IF_TIME(t_start = rtclock());
	printf("to know *pathDistanceMatrix  a  %p %p""",*a,&a[0][0]);

  int t1, t2, t3, t4, t5, t6;
 register int lbv, ubv;
/* Start of CLooG code */
if ((N >= 3) && (T >= 1)) {
  for (t1=0;t1<=floord(T-1,16);t1++) {
    for (t2=t1;t2<=min(floord(T+N-3,16),floord(16*t1+N+13,16));t2++) {
      for (t3=max(ceild(32*t2-N-12,16),t1+t2);t3<=min(min(min(min(floord(T+N-3,16),floord(16*t1+N+13,16)),floord(32*t2+N+27,16)),floord(16*t1+16*t2+N+30,16)),floord(16*t2+T+N+12,16));t3++) {
        for (t4=max(max(max(16*t1,16*t2-N+2),16*t3-N+2),-16*t2+16*t3-N-13);t4<=min(min(min(min(T-1,16*t1+15),16*t2+30),16*t3+14),-16*t2+16*t3+30);t4++) {
          for (t5=max(max(16*t2,t4+1),16*t3-t4-N+2);t5<=min(min(16*t2+15,16*t3-t4+30),t4+N-2);t5++) {
            for (t6=max(16*t3,t4+t5+1);t6<=min(16*t3+15,t4+t5+N-2);t6++) {
              a[(-t4+t5)][(-t4-t5+t6)] = (a[(-t4+t5)-1][(-t4-t5+t6)-1] + a[(-t4+t5)-1][(-t4-t5+t6)] + a[(-t4+t5)-1][(-t4-t5+t6)+1] + a[(-t4+t5)][(-t4-t5+t6)-1] + a[(-t4+t5)][(-t4-t5+t6)] + a[(-t4+t5)][(-t4-t5+t6)+1] + a[(-t4+t5)+1][(-t4-t5+t6)-1] + a[(-t4+t5)+1][(-t4-t5+t6)] + a[(-t4+t5)+1][(-t4-t5+t6)+1])/9.0;;
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
