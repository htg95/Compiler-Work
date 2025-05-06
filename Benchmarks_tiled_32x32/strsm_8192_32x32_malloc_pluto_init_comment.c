#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include <sys/time.h>
#include <unistd.h>
#include <malloc.h>

#define NMAX 10

int main()
{
	
	double **a;
	double **b;
	int size=(NMAX)*(NMAX)*sizeof(double);
    double t_start, t_end;
    long N=NMAX;
	int i;
 int _4_zeros=1<<28; 
 //profile_start
 a=(double **) malloc(sizeof(double *)*(NMAX));
 //profile_end
a[0]=(double*)memalign(_4_zeros,size);
b=(double **) malloc(sizeof(double *)*(NMAX));
b[0]=(double*)memalign(_4_zeros,size);
  return 0;
}
