#include <stdio.h>
#include <stdlib.h>
typedef unsigned long longer;
double** malloc2D(longer size){
	double** arr = (double**) malloc(sizeof(double*) * size);
	longer i;
	for(i=0;i<size;i++){
		arr[i] = (double*) malloc(sizeof(double) * size);
	}
	return arr;
}
void free2D(double** arr, longer size){
	longer i;
	for(i=0;i<size;i++){
		free(arr[i]);
	}
	free(arr);
}
double randFrom(double min, double max){
	double range = max - min;
	return min + rand() / (RAND_MAX / range);
}
void matrix_mult(double** a, double** b, double** c, longer size){
	longer i, j, k;
	for(i=0;i<size;i++){
		for(k=0;k<size;k++){
			c[i][j] = 0;
			for(j=0;j<size;j++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
int main(int argc, char** argv){
	if(argc != 2){
		printf("Invalid Args\n");
		return -1;
	}
	longer size = atoi(argv[1]);
	//----------------------------------------------------------------
	double** a = malloc2D(size);
	double** b = malloc2D(size);
	double** c = malloc2D(size);
	//----------------------------------------------------------------
	longer i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = randFrom(-1.0, 1.0);
			b[i][j] = randFrom(-1.0, 1.0);
		}
	}
	//----------------------------------------------------------------
	matrix_mult(a, b, c, size);
	//----------------------------------------------------------------
	free2D(a, size);
	free2D(b, size);
	free2D(c, size);
	return 0;
}
