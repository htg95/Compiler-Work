#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <malloc.h>
//#include <sys/time.h>

#define N 1024
//double a[N][N], y_1[N+17], y_2[N+19], x1[N+23], z0[N+29], x2[N+31];

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

// void init_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // y_1[i] = i;
        // y_2[i] = i+1;
        // x1[i] = 0.0;
        // x2[i] = 0.0;

        // for (j=0; j<N; j++)
            // a[i][j] = i+j+1.0;
    // }
// }

// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // fprintf(stderr, "%lf ", x1[i]);
        // if (j%80 == 20) fprintf(stderr, "\n");
    // }
    // fprintf(stderr, "\n");
    // for (i=0; i<N; i++) {
        // fprintf(stderr, "%lf ", x2[i]);
        // if (j%80 == 20) fprintf(stderr, "\n");
    // }
    // fprintf(stderr, "\n");
// }

int main()
{
    long double **a;
	long double y_1[N+17], y_2[N+19], x1[N+23], z0[N+29], x2[N+31];
    int i, j, k, l, t;
	int size=(N)*(N)*sizeof(long double);
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
    long double t_start, t_end;
	
	a=(long double **) malloc(sizeof(long double *)*(N));
	a[0]=(long double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	a[i]=(*a + N*i);
	}
  

    //IF_TIME(t_start = rtclock());




  int t1, t2, t3, t4;

 register int lbv, ubv;

/* Start of CLooG code */
if (N >= 1) {
  for (t1=0;t1<=floord(N-1,32);t1++) {
    for (t2=0;t2<=floord(N-1,32);t2++) {
      for (t3=32*t1;t3<=min(N-1,32*t1+31);t3++) {
        for (t4=32*t2;t4<=min(N-1,32*t2+31);t4++) {
          x1[t3] = x1[t3] + a[t3][t4] * y_1[t4];;
          x2[t3] = x2[t3] + a[t4][t3] * y_2[t4];;
        }
      }
    }
  }
}
/* End of CLooG code */

    /* IF_TIME(t_end = rtclock());
    IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

    if (fopen(".test", "r")) {
#ifdef MPI
        if (my_rank == 0) {
            print_array();
        }
#else
        print_array();
#endif
    } */
    return 0;
}
