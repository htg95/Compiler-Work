#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <unistd.h>
//#include <sys/time.h>

#define NMAX 8192
#pragma declarations

#pragma enddeclarations

/* #ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

#ifdef TIME
double rtclock()
{
    struct timezone Tzp;
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, &Tzp);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}
#endif */


int main()
{
  double **a;
  double **c; 	 
  double t_start, t_end;
  int   size=(NMAX)*(NMAX)*sizeof(double);
  int i,j, k;
  
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

/*
  for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      c[i][j] = 0.0;
      a[i][j] = i*j*3.2345 / NMAX;
    }
  }
*/
  //IF_TIME(t_start = rtclock());



  int t1, t2, t3, t4, t5, t6;

 register int lbv, ubv;

/* Start of CLooG code */
if (NMAX >= 1) {
  for (t1=0;t1<=floord(NMAX-1,16);t1++) {
    for (t2=t1;t2<=floord(NMAX-1,16);t2++) {
      for (t3=0;t3<=floord(NMAX-1,16);t3++) {
        for (t4=16*t1;t4<=min(NMAX-1,16*t1+15);t4++) {
          for (t5=16*t3;t5<=min(NMAX-1,16*t3+15);t5++) {
            lbv=max(16*t2,t4);
            ubv=min(NMAX-1,16*t2+15);
#pragma ivdep
#pragma vector always
            for (t6=lbv;t6<=ubv;t6++) {
              c[t4][t6] += a[t5][t4] * a[t5][t6];;
            }
          }
        }
      }
    }
  }
}
/* End of CLooG code */


  /* IF_TIME(t_end = rtclock());
  IF_TIME(fprintf(stdout, "%0.6lfs\n", t_end - t_start));

  if (fopen(".test", "r"))  {
#ifdef MPI
      if (my_rank == 0) {
#endif
    for (i = 0; i < NMAX; i++) {
      for (j = 0; j < NMAX; j++) {
        fprintf(stderr, "%lf ", c[i][j]);
      }
    }
  }
#ifdef MPI
      }
#endif */

  return 0;

}
