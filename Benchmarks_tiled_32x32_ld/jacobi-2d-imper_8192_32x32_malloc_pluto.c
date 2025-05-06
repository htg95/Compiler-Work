#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
//#include <sys/time.h>
#include<malloc.h>
#include <assert.h>

#define N 1024
#define T 1024

// #pragma declarations
// double a[N][N];
// double b[N][N];
// #pragma enddeclarations

// #ifdef TIME
// #define IF_TIME(foo) foo;
// #else
// #define IF_TIME(foo)
// #endif

// void init_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // a[i][j] = ((double)j)/N;
        // }
    // }
// }


// void print_array()
// {
    // int i, j;

    // for (i=0; i<N; i++) {
        // for (j=0; j<N; j++) {
            // fprintf(stderr, "%lf ", a[i][j]);
            // if (j%80 == 20) fprintf(stderr, "\n");
        // }
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
 #define __PLACE_TO_INSERT_FORWARD_DECLARATIONS

int main()
{
    double **a;
	double **b;
	int size=(N)*(N)*sizeof(double);
	int _4_zeros=1<<28;
	printf ("_4_zeros %d  %p \n",_4_zeros, _4_zeros);
    int t, i, j;
    double t_start, t_end;

	
	a=(double **) malloc(sizeof(double *)*(N));
	a[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	a[i]=(*a + N*i);
	}

	b=(double **) malloc(sizeof(double *)*(N));
	b[0]=(double*)memalign(_4_zeros,size);
	for(i=0;i<N;i++)
	{	
	b[i]=(*b + N*i);
	}
	printf("to know *pathDistanceMatrix  a  %p  b %p, "" %p, "" %p   \n",*a,*b,&a[0][0],&b[0][0]);

    init_array();

//    IF_TIME(t_start = rtclock());




  int t1, t2, t3, t4, t5, t6;

 register int lbv, ubv;

/* Start of CLooG code */
if ((N >= 4) && (T >= 1)) {
  for (t1=0;t1<=floord(T-1,32);t1++) {
    for (t2=2*t1;t2<=min(floord(2*T+N-3,32),floord(64*t1+N+61,32));t2++) {
      for (t3=max(ceild(32*t2-N-27,32),2*t1);t3<=min(min(floord(2*T+N-3,32),floord(64*t1+N+61,32)),floord(32*t2+N+27,32));t3++) {
        if ((t1 <= floord(32*t3-N+1,64)) && (t2 <= t3-1)) {
          if ((N+1)%2 == 0) {
            for (t5=max(32*t2,32*t3-N+4);t5<=32*t2+31;t5++) {
              a[(-32*t3+t5+N-2)][(N-2)]=b[(-32*t3+t5+N-2)][(N-2)];;
            }
          }
        }
        if ((t1 <= floord(32*t2-N+1,64)) && (t2 >= t3)) {
          if ((N+1)%2 == 0) {
            for (t6=max(32*t3,32*t2-N+4);t6<=min(32*t2,32*t3+31);t6++) {
              a[(N-2)][(-32*t2+t6+N-2)]=b[(N-2)][(-32*t2+t6+N-2)];;
            }
          }
        }
        if ((N == 4) && (t2 == t3)) {
          for (t4=max(32*t1,16*t2-1);t4<=min(min(T-1,32*t1+31),16*t2+14);t4++) {
            b[2][2]= 0.2*(a[2][2]+a[2][2 -1]+a[2][1+2]+a[1+2][2]+a[2 -1][2]);;
            a[2][2]=b[2][2];;
          }
        }
        if (t2 == t3) {
          for (t4=max(ceild(32*t2-N+2,2),32*t1);t4<=min(min(min(floord(32*t2-N+32,2),T-1),32*t1+31),16*t2-2);t4++) {
            for (t5=32*t2;t5<=2*t4+N-2;t5++) {
              for (t6=32*t2;t6<=2*t4+N-2;t6++) {
                b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
                a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
              }
              a[(-2*t4+t5-1)][(N-2)]=b[(-2*t4+t5-1)][(N-2)];;
            }
            for (t6=32*t2;t6<=2*t4+N-1;t6++) {
              a[(N-2)][(-2*t4+t6-1)]=b[(N-2)][(-2*t4+t6-1)];;
            }
          }
        }
        for (t4=max(max(ceild(32*t2-N+33,2),ceild(32*t3-N+2,2)),32*t1);t4<=min(min(min(floord(32*t3-N+32,2),T-1),32*t1+31),16*t2-2);t4++) {
          for (t5=32*t2;t5<=32*t2+31;t5++) {
            for (t6=32*t3;t6<=2*t4+N-2;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
            a[(-2*t4+t5-1)][(N-2)]=b[(-2*t4+t5-1)][(N-2)];;
          }
        }
        for (t4=max(max(ceild(32*t2-N+2,2),ceild(32*t3-N+33,2)),32*t1);t4<=min(min(min(floord(32*t2-N+32,2),T-1),32*t1+31),16*t3-2);t4++) {
          for (t5=32*t2;t5<=2*t4+N-2;t5++) {
            for (t6=32*t3;t6<=32*t3+31;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
          }
          for (t6=32*t3;t6<=32*t3+31;t6++) {
            a[(N-2)][(-2*t4+t6-1)]=b[(N-2)][(-2*t4+t6-1)];;
          }
        }
        for (t4=max(max(ceild(32*t2-N+33,2),ceild(32*t3-N+33,2)),32*t1);t4<=min(min(min(T-1,32*t1+31),16*t2-2),16*t3-2);t4++) {
          for (t5=32*t2;t5<=32*t2+31;t5++) {
            for (t6=32*t3;t6<=32*t3+31;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
          }
        }
        if ((N >= 5) && (t2 == t3)) {
          for (t4=max(32*t1,16*t2-1);t4<=min(min(floord(32*t2-N+32,2),T-1),32*t1+31);t4++) {
            for (t6=2*t4+2;t6<=2*t4+N-2;t6++) {
              b[2][(-2*t4+t6)]= 0.2*(a[2][(-2*t4+t6)]+a[2][(-2*t4+t6)-1]+a[2][1+(-2*t4+t6)]+a[1+2][(-2*t4+t6)]+a[2 -1][(-2*t4+t6)]);;
            }
            for (t5=2*t4+3;t5<=2*t4+N-2;t5++) {
              b[(-2*t4+t5)][2]= 0.2*(a[(-2*t4+t5)][2]+a[(-2*t4+t5)][2 -1]+a[(-2*t4+t5)][1+2]+a[1+(-2*t4+t5)][2]+a[(-2*t4+t5)-1][2]);;
              for (t6=2*t4+3;t6<=2*t4+N-2;t6++) {
                b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
                a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
              }
              a[(-2*t4+t5-1)][(N-2)]=b[(-2*t4+t5-1)][(N-2)];;
            }
            for (t6=2*t4+3;t6<=2*t4+N-1;t6++) {
              a[(N-2)][(-2*t4+t6-1)]=b[(N-2)][(-2*t4+t6-1)];;
            }
          }
        }
        if (t2 == t3) {
          for (t4=max(max(ceild(32*t2-N+33,2),32*t1),16*t2-1);t4<=min(min(T-1,32*t1+31),16*t2+14);t4++) {
            for (t6=2*t4+2;t6<=32*t2+31;t6++) {
              b[2][(-2*t4+t6)]= 0.2*(a[2][(-2*t4+t6)]+a[2][(-2*t4+t6)-1]+a[2][1+(-2*t4+t6)]+a[1+2][(-2*t4+t6)]+a[2 -1][(-2*t4+t6)]);;
            }
            for (t5=2*t4+3;t5<=32*t2+31;t5++) {
              b[(-2*t4+t5)][2]= 0.2*(a[(-2*t4+t5)][2]+a[(-2*t4+t5)][2 -1]+a[(-2*t4+t5)][1+2]+a[1+(-2*t4+t5)][2]+a[(-2*t4+t5)-1][2]);;
              for (t6=2*t4+3;t6<=32*t2+31;t6++) {
                b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
                a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
              }
            }
          }
        }
        for (t4=max(max(ceild(32*t3-N+2,2),32*t1),16*t2-1);t4<=min(min(min(min(floord(32*t3-N+32,2),T-1),32*t1+31),16*t2+14),16*t3-2);t4++) {
          for (t6=32*t3;t6<=2*t4+N-2;t6++) {
            b[2][(-2*t4+t6)]= 0.2*(a[2][(-2*t4+t6)]+a[2][(-2*t4+t6)-1]+a[2][1+(-2*t4+t6)]+a[1+2][(-2*t4+t6)]+a[2 -1][(-2*t4+t6)]);;
          }
          for (t5=2*t4+3;t5<=32*t2+31;t5++) {
            for (t6=32*t3;t6<=2*t4+N-2;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
            a[(-2*t4+t5-1)][(N-2)]=b[(-2*t4+t5-1)][(N-2)];;
          }
        }
        for (t4=max(max(ceild(32*t3-N+33,2),32*t1),16*t2-1);t4<=min(min(min(T-1,32*t1+31),16*t2+14),16*t3-2);t4++) {
          for (t6=32*t3;t6<=32*t3+31;t6++) {
            b[2][(-2*t4+t6)]= 0.2*(a[2][(-2*t4+t6)]+a[2][(-2*t4+t6)-1]+a[2][1+(-2*t4+t6)]+a[1+2][(-2*t4+t6)]+a[2 -1][(-2*t4+t6)]);;
          }
          for (t5=2*t4+3;t5<=32*t2+31;t5++) {
            for (t6=32*t3;t6<=32*t3+31;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
          }
        }
        for (t4=max(max(ceild(32*t2-N+2,2),32*t1),16*t3-1);t4<=min(min(min(min(floord(32*t2-N+32,2),T-1),32*t1+31),16*t2-2),16*t3+14);t4++) {
          for (t5=32*t2;t5<=2*t4+N-2;t5++) {
            b[(-2*t4+t5)][2]= 0.2*(a[(-2*t4+t5)][2]+a[(-2*t4+t5)][2 -1]+a[(-2*t4+t5)][1+2]+a[1+(-2*t4+t5)][2]+a[(-2*t4+t5)-1][2]);;
            for (t6=2*t4+3;t6<=32*t3+31;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
          }
          for (t6=2*t4+3;t6<=32*t3+31;t6++) {
            a[(N-2)][(-2*t4+t6-1)]=b[(N-2)][(-2*t4+t6-1)];;
          }
        }
        for (t4=max(max(ceild(32*t2-N+33,2),32*t1),16*t3-1);t4<=min(min(min(T-1,32*t1+31),16*t2-2),16*t3+14);t4++) {
          for (t5=32*t2;t5<=32*t2+31;t5++) {
            b[(-2*t4+t5)][2]= 0.2*(a[(-2*t4+t5)][2]+a[(-2*t4+t5)][2 -1]+a[(-2*t4+t5)][1+2]+a[1+(-2*t4+t5)][2]+a[(-2*t4+t5)-1][2]);;
            for (t6=2*t4+3;t6<=32*t3+31;t6++) {
              b[(-2*t4+t5)][(-2*t4+t6)]= 0.2*(a[(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)][(-2*t4+t6)-1]+a[(-2*t4+t5)][1+(-2*t4+t6)]+a[1+(-2*t4+t5)][(-2*t4+t6)]+a[(-2*t4+t5)-1][(-2*t4+t6)]);;
              a[(-2*t4+t5-1)][(-2*t4+t6-1)]=b[(-2*t4+t5-1)][(-2*t4+t6-1)];;
            }
          }
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
