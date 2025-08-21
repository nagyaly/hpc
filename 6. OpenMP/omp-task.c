#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
unsigned long ROW = 10;
unsigned long COL = 1e6;
double** alloc2D(){
	unsigned long i, j;
	double** matrix = (double**) malloc(sizeof(double*) * ROW);
	for(i=0;i<ROW;i++){
		matrix[i] = (double*) malloc(sizeof(double) * COL);
	}
	return matrix;
}
void free2D(double** matrix){
	unsigned long i;
	for(i=0;i<ROW;i++){
		free(matrix[i]);
	}
	free(matrix);
}
void init(double** matrix){
	unsigned long i, j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			matrix[i][j] = (i/100) + j;
		}
	}
}
int main(){
	//--------------------------------------- allocation
	double** a = alloc2D();
	double** b = alloc2D();
	double** c = alloc2D();
	init(a);
	init(b);
	//---------------------------------------
	unsigned long sum = 0;
	unsigned long i, j;
	for(i=0;i<ROW;i++){
		for(j=0;j<COL;j++){
			c[i][j] = a[i][j] + b[i][j];
			sum += c[i][j];
		}
	}
	printf("TOTAL Sum: %ld\n", sum);
	//--------------------------------------- deallocation
	free2D(a);
	free2D(b);
	free2D(c);
	//---------------------------------------
	return 0;
}
