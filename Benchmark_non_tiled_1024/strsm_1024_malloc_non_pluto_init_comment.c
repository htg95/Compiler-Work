#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/time.h>

#define NMAX 1024

// static double a[NMAX][NMAX], b[NMAX][NMAX];

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void init_array()
// {
    // int i, j;

    // for (i = 0; i < NMAX; i++) {
        // for (j = 0; j < NMAX; j++) {
            // b[i][j] = i*j*0.3+1;
            // a[i][j] = i+j+1;
        // }
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

// #define TIME 1

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void strsm(long N) {
	// int i,j,k;

// //#pragma scop
	// for (i=0; i<N; i++) {
		// for (j=0; j<N; j++) {
			// for (k=i+1; k<N; k++) {
				// if (k == i+1) b[j][i] /= a[i][i];
                // b[j][k] -= a[i][k] * b[j][i];
            // }
        // }
    // }
// //#pragma endscop
// }


int main()
{
	double **a;
	double **b;
	int size=(NMAX)*(NMAX)*sizeof(double);
    double t_start, t_end;
    long N=NMAX;
    int i,j;
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


    //IF_TIME(t_start = rtclock());
    int k;

//#pragma scop
	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			for (k=i+1; k<N; k++) {
				if (k == i+1) b[j][i] /= a[i][i];
                b[j][k] -= a[i][k] * b[j][i];
            }
        }
    }
    //IF_TIME(t_end = rtclock());

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
