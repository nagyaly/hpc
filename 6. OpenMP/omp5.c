#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
unsigned long SIZE = 2e4;
double** alloc2D(){
	unsigned long i, j;
	double** matrix = (double**) malloc(sizeof(double*) * SIZE);
	for(i=0;i<SIZE;i++){
		matrix[i] = (double*) malloc(sizeof(double) * SIZE);
	}
	return matrix;
}
void free2D(double** matrix){
	unsigned long i, j;
	for(i=0;i<SIZE;i++){
		free(matrix[i]);
	}
	free(matrix);
}
void init(double** matrix){
	unsigned long i, j;
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			matrix[i][j] = (i/100) + j;
		}
	}
}
int main(){
	//--------------------------------------- allocation
	double** matrix = alloc2D();
	init(matrix);
	//---------------------------------------
	unsigned long sum = 0;
	unsigned long i, j;
	#pragma omp parallel num_threads(10) reduction(+:sum)
	{
		//will result in 10 instance of j
		#pragma omp for private(j)
		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++){
				sum += matrix[i][j];
			}
		}
		printf("Sub Sum: %ld\n", sum);
	}
	printf("TOTAL Sum: %ld\n", sum);
	//--------------------------------------- deallocation
	free2D(matrix);
	//---------------------------------------
	return 0;
}
