#include <math.h>
#include "/home/mdl/sug241/projects/gem5_learn_minli/2D_Surya/learn/TDC_micro/base/gem5/include/gem5/asm/generic/m5ops.h"
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
#include <setjmp.h>
//#define __USE_GNU
#include <signal.h>
#include <ucontext.h>
sigjmp_buf sigbuf;
double sigrv;
//using namespace std;
//void* memalign(int long, int long);
void sigill_handler(int sn, siginfo_t *si, void *sc)
{
  //ucontext_t *uc = (ucontext_t *)sc;
  //mcontext_t *mc = &uc->uc_mcontext; /* non-portable */

  /* TODO: verify the illegal instruction */

 // sigrv = mc->gregs[REG_RDI] + mc->gregs[REG_RSI];

  longjmp(sigbuf, 0);
}

#define NMAX 256
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

void profile1_start()
{
printf("in profile_start\n");
}


void profile1_end()
{
printf("in profile_end\n");
}

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


  for (i = 0; i < NMAX; i++) {
    for (j = 0; j < NMAX; j++) {
      c[i][j] = 0.0;
      a[i][j] = i*j*3.2345 / NMAX;
    }
  }

//start check point
struct sigaction sa;
  double rv;
  sa.sa_flags = SA_NODEFER;
  sa.sa_sigaction = (void (*)(int, siginfo_t *, void *))sigill_handler;
  if ( sigaction( SIGILL, &sa, (struct sigaction*)NULL ) ) {
    printf( "Unable to register signal handler\n");
    return 1;
  }
  
  if ( !sigsetjmp(sigbuf, 0) ) {
    //rv =  m5_dump_stats(0,0);
    m5_dump_stats(0,0);
    m5_checkpoint(0,0);
  } else {
    rv = sigrv;
  }
printf("%d\n", rv);
profile1_start();

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

profile1_end();
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
