#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <malloc.h>
#define N 8192

#define alpha 1
#define beta 1


#include <unistd.h>
//#include <sys/time.h>

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif



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

#define beta 1
#define alpha 1

main()
{	
	double **A;
	double **B;
	int   size=(N)*(N)*sizeof(double);
	
	double x[N];
	double u1[N];
	double u2[N];
	double v2[N];
	double v1[N];
	double w[N];
	double y[N];
	double z[N];

    double t_start, t_end;
    int i, j;
	
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
	
	A=(double **) malloc(sizeof(double *)*(N));
	A[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	A[i]=(*A +(N)*i);
	}
	
	B=(double **) malloc(sizeof(double *)*(N));
	B[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	B[i]=(*B +(N)*i);
	}
	
   void init_array()
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
            A[i][j] = ((double) i*j)/N;
        }
    }
}

    //IF_TIME(t_start = rtclock());

    /* pluto start (N,alpha,beta) */


printf("to know *pathDistanceMatrix  A  %p  B %p, "" %p, "" %p   \n",*A,*B,&A[0][0],&B[0][0]);


  int t1, t2, t3, t4, t5, t6;

 register int lbv, ubv;

/* Start of CLooG code */
if (N >= 1) {
  for (t2=0;t2<=floord(N-1,16);t2++) {
    for (t3=0;t3<=floord(N-1,16);t3++) {
      for (t4=16*t3;t4<=min(N-1,16*t3+15);t4++) {
        lbv=16*t2;
        ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
        for (t5=lbv;t5<=ubv;t5++) {
          A[t4][t5] = A[t4][t5] + u1[t4]*v1[t5] + u2[t4]*v2[t5];;
          x[t5] = x[t5] + beta* A[t4][t5]*y[t4];;
        }
      }
    }
  }
  for (t2=0;t2<=floord(N-1,16);t2++) {
    lbv=16*t2;
    ubv=min(N-1,16*t2+15);
#pragma ivdep
#pragma vector always
    for (t3=lbv;t3<=ubv;t3++) {
      x[t3] = x[t3] + z[t3];;
    }
  }
  for (t2=0;t2<=floord(N-1,16);t2++) {
    for (t3=0;t3<=floord(N-1,16);t3++) {
      for (t4=16*t2;t4<=min(N-1,16*t2+15);t4++) {
        for (t5=16*t3;t5<=min(N-1,16*t3+15);t5++) {
          w[t4] = w[t4] + alpha* A[t4][t5]*x[t5];;
        }
      }
    }
  }
}
/* End of CLooG code */

    /* pluto end */
    // IF_TIME(t_end = rtclock());
    // IF_TIME(printf("%0.6lfs\n", t_end - t_start));

// #ifdef TEST
    // print_array();
// #endif

    return 0;
}

