#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
unsigned long ROW = 5, COL=1e8;
double** alloc2D(){
	unsigned long i, j;
	double** matrix = (double**) malloc(sizeof(double*) * ROW);
	for(i=0;i<ROW;i++){
		matrix[i] = (double*) malloc(sizeof(double) * COL);
	}
	return matrix;
}
void free2D(double** matrix){
	unsigned long i, j;
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
	double** matrix = alloc2D();
	init(matrix);
	//---------------------------------------
	unsigned long sum = 0;
	unsigned long i, j;
	#pragma omp parallel num_threads(10) reduction(+:sum)
	{
		//parallize outer and (part) of the inner loop
		#pragma omp for collapse(2) private(j)
		for(i=0;i<ROW;i++){
			//>>>>
			for(j=0;j<COL;j++){
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

/*
		4 threads	row 4	col 10
		- - - - - - - - - -
		* * * * * * * * * *
		+ + + + + + + + + +
		# # # # # # # # # #

		8 threads	row 4 col 10
		- - - - - * * * * *
		% % % % % + + + + +
		# # # # # & & & & &
		@ @ @ @ @ $ $ $ $ $
*/

