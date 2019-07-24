#include <stdio.h>

int main(){

	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

	printf("Enter the number of rows of the first matrix\n");
	scanf("%d", &row1); //read input to row1
	printf("Enter the number of columns of the first matrix\n");
	scanf("%d", &col1); //read input to col1
	printf("Enter the number of rows of the first matrix\n");
	scanf("%d", &row2); //read input to row2
	printf("Enter the number of rows of the first matrix\n");
	scanf("%d", &col2); //read input to col2

	double *matrix1 = 0;
	matrix1 = (double *)malloc(row1 * col1 * sizeof(double*));
	for (int i = 0; i < row1; i++){
		for (int j = 0; j < col1; j++){
			matrix1[i + j*row1] = i*j;		
		}
	}

	double *matrix2 = 0;
	matrix2 = (double *)malloc(row2 * col2 * sizeof(double*));
	for (int i = 0; i < row2; i++){
		for (int j = 0; j < col2; j++){
			matrix2[i + j*row2] = i*j;		
		}
	}

	double *matrix3 = 0;
	matrix3 = (double *)malloc(row1 * col2 * sizeof(double*));
	for (int i = 0; i < row1; i++){
		for (int j = 0; j < col2; j++){
			double sum = 0;			
			for (int k = 0; k < col1; k++){
				 sum = matrix1[i + k*col1] * matrix2[k + i*row2] //stopped here

			}			
			matrix2[i + j*row2] = i*j;		
		}
	}

}
