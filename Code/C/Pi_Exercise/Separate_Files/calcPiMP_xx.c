#include <omp.h>
#include <stdio.h>

static int long numSteps = 1000000;
int main(){

	double pi = 0; double time = 0;
	
	double deltaX = 1.0/numSteps;
	double start = omp_get_wtime();	
	int nThreads = 0;
	#pragma omp parallel for reduction(+:pi)
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + new_deltaX*new_deltaX);
		pi += F_of_x * deltaX;
		if (i == 0) nThreads = omp_get_num_threads();	
	}
	printf("Number of cores %d\n", nThreads);
	printf("PI = %f, duration: %f ms\n", pi, omp_get_wtime() - start);
	
}
