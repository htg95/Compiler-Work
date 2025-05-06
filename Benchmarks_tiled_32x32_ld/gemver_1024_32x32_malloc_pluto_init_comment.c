#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
//#include <sys/time.h>
#include <stdlib.h>

#define N 1024

#define alpha 1
#define beta 1

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void init_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // u1[i] = i;
        // u2[i] = (i+1)/N/2.0;
        // v1[i] = (i+1)/N/4.0;
        // v2[i] = (i+1)/N/6.0;
        // y[i] = (i+1)/N/8.0;
        // z[i] = (i+1)/N/9.0;
        // x[i] = 0.0;
        // w[i] = 0.0;
        // for (j=0; j<N; j++) {
            // A[i][j] = ((double) i*j)/N;
        // }
    // }
// }

// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // fprintf(stderr, "%0.2lf ", w[i]);
        // if (i%80 == 20) fprintf(stderr, "\n");
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
	long double **A;
	long double **B;
	int   size=(N)*(N)*sizeof(long double);
	
	long double x[N];
	long double u1[N];
	long double u2[N];
	long double v2[N];
	long double v1[N];
	long double w[N];
	long double y[N];
	long double z[N];

    long double t_start, t_end;
    int i, j;
	
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
	
	A=(long double **) malloc(sizeof(long double *)*(N));
	A[0]=(long double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	A[i]=(*A +(N)*i);
	}
	
	B=(long double **) malloc(sizeof(long double *)*(N));
	B[0]=(long double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	B[i]=(*B +(N)*i);
	}
	
  /*  void init_array()
   {
    int i, j;

    for (i=0; i<N; i++) {
        u1[i] = i;
        u2[i] = (i+1)/N/2.0;
        v1[i] = (i+1)/N/4.0;
        v2[i] = (i+1)/N/6.0;
        y[i] = (i+1)/N/8.0;
        z[i] = (i+1)/N/9.0;
        x[i] = 0.0;
        w[i] = 0.0;
        for (j=0; j<N; j++) {
            A[i][j] = ((long double) i*j)/N;
        }
    }
} */

    //IF_TIME(t_start = rtclock());

    /* pluto start (N,alpha,beta) */


printf("to know *pathDistanceMatrix  A  %p  B %p, "" %p, "" %p   \n",*A,*B,&A[0][0],&B[0][0]);


  int t1, t2, t3, t4, t5, t6;

 register int lbv, ubv;
/* Start of CLooG code */
if (N >= 1) {
  for (t2=0;t2<=floord(N-1,32);t2++) {
    for (t3=0;t3<=floord(N-1,32);t3++) {
      for (t4=32*t3;t4<=min(N-1,32*t3+31);t4++) {
        lbv=32*t2;
        ubv=min(N-1,32*t2+31);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          B[t4][t5] = A[t4][t5] + u1[t4]*v1[t5] + u2[t4]*v2[t5];;
          x[t5] = x[t5] + beta* B[t4][t5]*y[t4];;
        }
      }
    }
  }
  for (t2=0;t2<=floord(N-1,32);t2++) {
    lbv=32*t2;
    ubv=min(N-1,32*t2+31);
#pragma ivdep
#pragma vector always
    for (t3=lbv;t3<=ubv;t3++) {
      x[t3] = x[t3] + z[t3];;
    }
  }
  for (t2=0;t2<=floord(N-1,32);t2++) {
    for (t3=0;t3<=floord(N-1,32);t3++) {
      for (t4=32*t2;t4<=min(N-1,32*t2+31);t4++) {
        for (t5=32*t3;t5<=min(N-1,32*t3+31);t5++) {
          w[t4] = w[t4] + alpha* B[t4][t5]*x[t5];;
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
