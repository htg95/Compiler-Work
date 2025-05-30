#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <unistd.h>
//#include <sys/time.h>
#include <math.h>
#include <malloc.h>
#define my_sqrt_array(x,j) sqrt(x[j])

#define N 1023
#define M 1023



/* #ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif */


/* void print_array()
{
  int i, j;
  int n = N;
  int m = M;
  for (i=1; i<=m; i++) {
    for (j=1; j<=m; j++) {
      fprintf(stderr, "%0.2lf ", symmat[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "\n");
} */

/* double rtclock()
{
  struct timezone Tzp;
  struct timeval Tp;
  int stat;
  stat = gettimeofday (&Tp, &Tzp);
  if (stat != 0) printf("Error return from gettimeofday: %d",stat);
  return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
} */

/* #ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif */

int main(int argc, char** argv)
{

double **data;
double **symmat;
	

int   size=(M+1)*(N+1)*sizeof(double);	

double float_n = (float) N;
double eps = 0.005;
double stddev[M + 1];
double mean[M + 1];
	
  double t_start, t_end;
  int i, j, j1, j2;
int _4_zeros=1<<28;
printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);

data=(double **) malloc(sizeof(double *)*(M+1));
data[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<M+1;i++)
{	
data[i]=(*data + (N+1)*i);
}
  // void init_array()
// {
    // int i, j;
    // int n = N;
    // int m = M;

    // for (i=0; i<=n; i++) {
      // for (j=0; j<=m; j++) {
        // data[i][j] = ((float) i*j)/N;
      // }
    // }
// }

symmat=(double **) malloc(sizeof(double *)*(M+1));
symmat[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<M+1;i++)
{	
symmat[i]=(*symmat + (N+1)*i);
}
  //IF_TIME(t_start = rtclock());
printf("to know *pathDistanceMatrix  data  %p  symmat %p, "" %p, "" %p   \n",*data,*symmat,&data[0][0],&symmat[0][0]);
  /* Determine mean of column vectors of input data matrix */
  for (j = 1; j <= M; j++) {
    mean[j] = 0.0;
    for (i = 1; i <= N; i++)
      mean[j] += data[i][j];
    mean[j] /= float_n;
  }

  /* Center the column vectors. */
  for (i = 1; i <= N; i++)
    for (j = 1; j <= M; j++)
      data[i][j] -= mean[j];

  for (j1 = 1; j1 <= M; j1++) {
    for (j2 = j1; j2 <= M; j2++) {
      symmat[j1][j2] = 0.0;
    }
  }

//#pragma scop
  /* Calculate the m * m covariance matrix. */
  for (j1 = 1; j1 <= M; j1++) {
    for (j2 = j1; j2 <= M; j2++) {
      for (i = 1; i <= N; i++) {
        symmat[j1][j2] += data[i][j1] * data[i][j2];
      }
      symmat[j2][j1] = symmat[j1][j2];
    }
  }
//#pragma endscop

  /* IF_TIME(t_end = rtclock());
  IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  if (fopen(".test", "r"))  {
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
