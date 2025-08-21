#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float** malloc2D(unsigned long int size){
	float** arr = (float**) malloc(sizeof(float*) * size);
	unsigned long int i;
	for(i=0;i<size;i++){
		arr[i] = (float*) malloc(sizeof(float) * size);
	}
	return arr;
}
void free2D(float** arr, unsigned long int size){
	unsigned long int i;
	for(i=0;i<size;i++){
		free(arr[i]);
	}
	free(arr);
}
float randFrom(float min, float max){
	float range = max - min;
	return min + rand() / (RAND_MAX / range);
}
void matrix_mult(float** a, float** b, float** c, unsigned long int size){
	unsigned long int i, j, k;
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
	unsigned long int size = atoi(argv[1]);
	//----------------------------------------------------------------
	float** a = malloc2D(size);
	float** b = malloc2D(size);
	float** c = malloc2D(size);
	//----------------------------------------------------------------
	unsigned long int i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = randFrom(-1.0, 1.0);
			b[i][j] = randFrom(-1.0, 1.0);
		}
	}
	//----------------------------------------------------------------
    clock_t start = clock();
	matrix_mult(a, b, c, size);
    clock_t end = clock();
    printf("Elapsed: %.6f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
	//----------------------------------------------------------------
	free2D(a, size);
	free2D(b, size);
	free2D(c, size);
	return 0;
}
