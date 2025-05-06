#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#define NMAX 1024

//#pragma declarations
//double a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];
//#pragma enddeclarations

// #define TIME 1

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


int main()
{
  double **a;
  double **b;
  double **c;
  int i,j, k;
  double t_start, t_end;
  
int size=(NMAX)*(NMAX)*sizeof(double);
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



  /* for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      b[i][j] = i+j;
      a[i][j] = i*j*0.5;
    }
  } */

  //IF_TIME(t_start = rtclock());
 c=(double **) malloc(sizeof(double *)*(NMAX));
c[0]=(double*)memalign(_4_zeros,size);
for(i=0;i<NMAX;i++)
{	
c[i]=(*c + (NMAX)*i);
}
 
printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*a,*b,&a[0][0],&b[0][0]);


  // for (i = 0; i < NMAX; i++) {
    // for (j = 0; j < NMAX; j++) {
      // c[i][j] = 0.0;
      // a[i][j] = b[i][j] = i*j*0.5 / NMAX;
    // }
  // }

  //IF_TIME(t_start = rtclock());

//#pragma scop
  for (i=0; i<NMAX; i++) {
    for (j=0; j<NMAX; j++) {
      for (k=0; k<j-1; k++) {
        c[i][k] += a[j][k] * b[i][j];
        c[i][j] += a[j][j] * b[i][j];
      }
      c[i][j] += a[j][j] * b[i][j];
    }
  }
//#pragma endscop

  // IF_TIME(t_end = rtclock());
  // IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  // if (fopen(".test", "r"))  {
// #ifdef MPI
      // if (my_rank == 0) {
// #endif
          // for (i = 0; i < NMAX; i++) {
              // for (j = 0; j < NMAX; j++) {
                  // fprintf(stderr, "%lf ", c[i][j]);
              // }
              // fprintf(stderr, "\n");
          // }
// #ifdef MPI
      // }
// #endif
  // }

  return 0;
}
