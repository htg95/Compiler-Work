#include <stdio.h>
#include <unistd.h>
//#include <sys/time.h>
#include <stdlib.h>
#include <malloc.h>
#define N 1024

#define alpha 1
#define beta 1

//#pragma declarations


double x[N];
double u1[N];
double u2[N];
double v2[N];
double v1[N];
double w[N];
double y[N];
double z[N];
//#pragma enddeclarations

/* #ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif
 */


/* void print_array()
{
    int i, j;

    for (i=0; i<N; i++) {
        fprintf(stderr, "%0.2lf ", w[i]);
        if (i%80 == 20) fprintf(stderr, "\n");
    }
    fprintf(stderr, "\n");
}
 */

/* double rtclock()
{
    struct timezone tzp;
    struct timeval tp;
    int stat;
    stat = gettimeofday (&tp, &tzp);
    if (stat != 0) printf("error return from gettimeofday: %d",stat);
    return(tp.tv_sec + tp.tv_usec*1.0e-6);
}
 */
int main()
{
 // double A[N][N];
 // double B[N][N];
double  **A;
double  **B;
  double t_start, t_end;
    int i, j;

int   size=(N)*(N)*sizeof(double);
int _4_zeros=1<<28;	
printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
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
printf("to know *pathDistanceMatrix  data  %p  symmat %p, "" %p, "" %p   \n",*A,*B,&A[0][0],&B[0][0]);

  
  //  init_array();

    

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

    //IF_TIME(t_start = rtclock());

//#pragma scop
    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            B[i][j] = A[i][j] + u1[i]*v1[j] + u2[i]*v2[j];

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            x[i] = x[i] + beta* B[j][i]*y[j];


    for (i=0; i<N; i++)
        x[i] = x[i] + z[i];

    for (i=0; i<N; i++)
        for (j=0; j<N; j++)
            w[i] = w[i] + alpha* B[i][j]*x[j];
//#pragma endscop

   /*  IF_TIME(t_end = rtclock());
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
