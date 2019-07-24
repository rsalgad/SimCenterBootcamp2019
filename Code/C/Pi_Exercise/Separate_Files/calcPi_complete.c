#include <omp.h>
#include <stdio.h>
#include <math.h>

static int long numSteps = 100000000;
int main(){

	printf("Single Core\n");	

	double pi = 0; double time = 0;
	
	double deltaX = 1.0/numSteps;
	double start = omp_get_wtime();	
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + pow(new_deltaX,2));
		pi += F_of_x * deltaX;
	}
	
	printf("PI = %f, duration: %f s\n", pi, omp_get_wtime() - start);
	
	printf("\n");
	printf("Parallel w/ math.h and reduction\n");
	
	pi = 0;
	int nThreads = 0;
	double start2 = omp_get_wtime();	
	#pragma omp parallel for reduction(+:pi)
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + pow(new_deltaX,2));
		pi += F_of_x * deltaX;
		if (i == 0) nThreads = omp_get_num_threads();
	}
	
	printf("Number of cores %d\n", nThreads);
	printf("PI = %f, duration: %f s\n", pi, omp_get_wtime() - start2);

	printf("\n");
	printf("Parallel w/ math.h and w/o reduction\n");
	
	pi = 0;
	int PAD = 64;
	double start3 = omp_get_wtime();	
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
	printf("PI = %f, duration: %f s\n", pi, omp_get_wtime() - start3);
	
	printf("\n");
	printf("Parallel w/o math.h and w/o reduction\n");
	
	pi = 0;
	double start4 = omp_get_wtime();	
	#pragma omp parallel for reduction(+:pi)
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + new_deltaX*new_deltaX);
		pi += F_of_x * deltaX;
		if (i == 0) nThreads = omp_get_num_threads();	
	}
	printf("Number of cores %d\n", nThreads);
	printf("PI = %f, duration: %f s\n", pi, omp_get_wtime() - start4);

}


