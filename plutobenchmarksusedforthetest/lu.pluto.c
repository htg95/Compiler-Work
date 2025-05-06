#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))





  int t1, t2, t3;

 register int lbv, ubv;

/* Start of CLooG code */
if (N >= 2) {
  for (t1=0;t1<=N-2;t1++) {
    lbv=t1+1;
    ubv=N-1;
#pragma ivdep
#pragma vector always
    for (t3=lbv;t3<=ubv;t3++) {
      a[t1][t3] = a[t1][t3]/a[t1][t1];;
    }
    for (t2=t1+1;t2<=N-1;t2++) {
      lbv=t1+1;
      ubv=N-1;
#pragma ivdep
#pragma vector always
      for (t3=lbv;t3<=ubv;t3++) {
        a[t2][t3] = a[t2][t3] - a[t2][t1]*a[t1][t3];;
      }
    }
  }
}
/* End of CLooG code */

