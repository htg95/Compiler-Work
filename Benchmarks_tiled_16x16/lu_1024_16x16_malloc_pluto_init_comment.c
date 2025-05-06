#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
//#include <sys/time.h>
#include<malloc.h>

#define N 1024

// #pragma declarations
// double a[N][N];
// //double v_a[32][35];
// //double v_b[32][32];
// //double v_c[32][33];
// #pragma enddeclarations

#include <unistd.h>
#include <sys/time.h>
#include <math.h>

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void init_array()
// {
    // int i, j, k;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // for (k=0; k<N; k++) {
                // a[i][j] += (i+k+1)*(k+j+1);//i==j?1:0;
            // }
        // }
    // }
// }


// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // fprintf(stderr, "%lf ", round(a[i][j]));
            // if (j%80 == 79) fprintf(stderr, "\n");
        // }
        // fprintf(stderr, "\n");
    // }
    // fprintf(stderr, "\n");
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

int main()
{
	int i, j, k;
    double t_start, t_end;
	double **a;
	// init_array() ;
		int   size=(N)*(N)*sizeof(double);
    // init_array() ;
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros); 
	// IF_TIME(t_start = rtclock());
	a=(double **) malloc(sizeof(double *)*(N));
  a[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	a[i]=(*a + N*i);
	}
    // IF_TIME(t_start = rtclock());
	printf("to know *pathDistanceMatrix  a  %p %p""",*a,&a[0][0]);
	
  int t1, t2, t3, t4, t5, t6;
 register int lbv, ubv;
/* Start of CLooG code */
if (N >= 2) {
  for (t1=0;t1<=floord(N-2,16);t1++) {
    for (t2=t1;t2<=floord(N-1,16);t2++) {
      for (t3=t1;t3<=floord(N-1,16);t3++) {
        if (t1 == t3) {
          for (t4=16*t1;t4<=min(N-2,16*t1+14);t4++) {
            lbv=max(16*t2,t4+1);
            ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
            for (t6=lbv;t6<=ubv;t6++) {
              a[t4][t6] = a[t4][t6]/a[t4][t4];;
            }
            for (t5=t4+1;t5<=min(N-1,16*t1+15);t5++) {
              lbv=max(16*t2,t4+1);
              ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
              for (t6=lbv;t6<=ubv;t6++) {
                a[t5][t6] = a[t5][t6] - a[t5][t4]*a[t4][t6];;
              }
            }
          }
        }
        if ((t1 == t3) && (t1 <= t2-1)) {
          lbv=16*t2;
          ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
          for (t6=lbv;t6<=ubv;t6++) {
            a[(16*t1+15)][t6] = a[(16*t1+15)][t6]/a[(16*t1+15)][(16*t1+15)];;
          }
        }
        if (t1 <= t3-1) {
          for (t4=16*t1;t4<=min(16*t1+15,16*t2+14);t4++) {
            for (t5=16*t3;t5<=min(N-1,16*t3+15);t5++) {
              lbv=max(16*t2,t4+1);
              ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
              for (t6=lbv;t6<=ubv;t6++) {
                a[t5][t6] = a[t5][t6] - a[t5][t4]*a[t4][t6];;
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
