#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
typedef unsigned long longer;
double **a, **b, **c;
longer size, tcount;
//--------------------------------------------------------------------
//allocate 2D arrray of double
double** malloc2D(longer size){
	double** arr = (double**) malloc(sizeof(double*) * size);
	longer i;
	for(i=0;i<size;i++){
		arr[i] = (double*) malloc(sizeof(double) * size);
	}
	return arr;
}
//--------------------------------------------------------------------
void free2D(double** arr, longer size){
	longer i;
	for(i=0;i<size;i++){
		free(arr[i]);
	}
	free(arr);
}
//--------------------------------------------------------------------
double randFrom(double min, double max){
	double range = max - min;
	return min + rand() / (RAND_MAX / range);
}
//--------------------------------------------------------------------
void* mm_routine(void* raw_args){
	int* id = (int*) raw_args;
	longer portion = size / tcount;
	longer start = *id * portion;
	longer end = start + portion;
	printf("Thread %d: from %ld to %ld\n", *id, start, end);
	longer i, j, k;
	for(i=start;i<end;i++){
		for(j=0;j<size;j++){
			c[i][j] = 0;
			for(k=0;k<size;k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}
//--------------------------------------------------------------------
int main(int argc, char** argv){
	if(argc != 3){
		printf("Invalid Args\n");
		return -1;
	}
	size = atoi(argv[1]);
	tcount = atoi(argv[2]);
	if(size % tcount != 0){
		printf("Invalid thread count\n");
		return -1;
	}
	//----------------------------------------------------------------
	a = malloc2D(size);
	b = malloc2D(size);
	c = malloc2D(size);
	//----------------------------------------------------------------
	longer i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = randFrom(-1.0, 1.0);
			b[i][j] = randFrom(-1.0, 1.0);
		}
	}
	//----------------------------------------------------------------
	pthread_t tids[tcount];
	int tidx[tcount];				//array for thread ids (sequence)
	for(i=0;i<tcount;i++){
		tidx[i] = i;
		pthread_create(&tids[i], NULL, mm_routine, &tidx[i]);
	}
	//----------------------------------------------------------------
	pthread_exit(NULL);
	free2D(a, size);
	free2D(b, size);
	free2D(c, size);
	return 0;
}
