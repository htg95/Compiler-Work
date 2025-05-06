#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <unistd.h>
//#include <sys/time.h>

#define NMAX 8192
//#pragma declarations
//double a[NMAX][NMAX], c[NMAX][NMAX];
//#pragma enddeclarations


int main()
{
  double t_start, t_end;

  int i,j, k;
  
  double **a;
  double **c; 	 
  //double t_start, t_end;
  int   size=(NMAX)*(NMAX)*sizeof(double);
  //int i,j, k;
  
  int _4_zeros=1<<28;
  printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);  
  
  a=(double **) malloc(sizeof(double *)*(NMAX));
  a[0]=(double*)memalign(_4_zeros,size);
  for(i=0;i<NMAX;i++)
	{	
	a[i]=(*a + (NMAX)*i);
	}
	
  c=(double **) malloc(sizeof(double *)*(NMAX));
  c[0]=(double*)memalign(_4_zeros,size);
  for(i=0;i<NMAX;i++)
	{	
	c[i]=(*c + (NMAX)*i);
	}
printf("to know *pathDistanceMatrix  a  %p  c %p, "" %p, "" %p   \n",*a,*c,&a[0][0],&c[0][0]);

  /* for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      c[i][j] = 0.0;
      a[i][j] = i*j*3.2345 / NMAX;
    }
  }
 */

//#pragma scop
  for (i=0; i<NMAX; i++) {
    for (j=0; j<NMAX; j++) {
      for (k=j; k<NMAX; k++) {
        c[j][k] += a[i][j] * a[i][k];
      }
    }
  }
//#pragma endscop
printf("Run successful");

  //IF_TIME(t_end = rtclock());
  //IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

/*   if (fopen(".test", "r"))  {
#ifdef MPI
      if (my_rank == 0) {
#endif
    for (i = 0; i < NMAX; i++) {
      for (j = 0; j < NMAX; j++) {
        fprintf(stderr, "%lf ", c[i][j]);
 */      /* }
    }
  }
#ifdef MPI
      }
#endif */

  return 0;

}
