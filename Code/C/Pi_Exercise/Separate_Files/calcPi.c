#include <omp.h>
#include <stdio.h>
#include <math.h>

static int long numSteps = 100000;
int main(){

	double pi = 0; double time = 0;
	
	double deltaX = 1.0/numSteps;
	double start = omp_get_wtime();	
	for (int i = 0; i < numSteps; i++){
		double new_deltaX = deltaX * (i + (1.0 / 2));
		double F_of_x = 4.0 / (1 + pow(new_deltaX,2));
		pi += F_of_x * deltaX;
	}
	
	printf("PI = %f, duration: %f ms\n", pi, omp_get_wtime() - start);
	
}
