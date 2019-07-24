#include <omp.h>
#include <stdio.h>
#include <math.h>

static int long numSteps = 100000;
int main(){

	double pi = 0; double time = 0;
	int PAD = 64;
	int nThreads = 0;
	double deltaX = 1.0/numSteps;
	double start = omp_get_wtime();	
	double sum[64][PAD];	


	#pragma omp parallel for
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + pow(new_deltaX,2));
		sum[omp_get_thread_num()][0] += F_of_x * deltaX;
		if (i == 0) nThreads = omp_get_num_threads();		
	}
	
	for(int i = 0; i < nThreads; i++)	
	pi += sum[i][0];

	printf("Number of cores %d\n", nThreads);
	printf("PI = %f, duration: %f ms\n", pi, omp_get_wtime() - start);
	
}
