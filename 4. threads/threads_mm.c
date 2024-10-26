#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
float **a, **b, **c;
unsigned long int size, tcount;
//--------------------------------------------------------------------
//allocate 2D arrray of float
float** malloc2D(unsigned long int size){
	float** arr = (float**) malloc(sizeof(float*) * size);
	unsigned long int i;
	for(i=0;i<size;i++){
		arr[i] = (float*) malloc(sizeof(float) * size);
	}
	return arr;
}
//--------------------------------------------------------------------
void free2D(float** arr, unsigned long int size){
	unsigned long int i;
	for(i=0;i<size;i++){
		free(arr[i]);
	}
	free(arr);
}
//--------------------------------------------------------------------
float randFrom(float min, float max){
	float range = max - min;
	return min + rand() / (RAND_MAX / range);
}
//--------------------------------------------------------------------
void* mm_routine(void* raw_args){
	int* id = (int*) raw_args;
	unsigned long int portion = size / tcount;
	unsigned long int start = *id * portion;
	unsigned long int end = start + portion;
	printf("Thread %d: from %ld to %ld\n", *id, start, end);
	unsigned long int i, j, k;
	for(i=0;i<size;i++){
		for(j=start;j<end;j++){
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
	unsigned long int i, j;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			a[i][j] = randFrom(-1.0, 1.0);
			b[i][j] = randFrom(-1.0, 1.0);
		}
	}
	//----------------------------------------------------------------
	clock_t start = clock();
	pthread_t tids[tcount];
	int tidx[tcount];				//array for thread ids (sequence)
	for(i=0;i<tcount;i++){
		tidx[i] = i;
		pthread_create(&tids[i], NULL, mm_routine, &tidx[i]);
	}
	//----------------------------------------------------------------
	for(i=0;i<tcount;i++){
		pthread_join(tids[i], NULL);
	}
	clock_t end = clock();
	printf("%ld Threads elapsed: %.6f sec\n", tcount, (double)(end - start) / CLOCKS_PER_SEC);
	//----------------------------------------------------------------
	free2D(a, size);
	free2D(b, size);
	free2D(c, size);
	pthread_exit(NULL);
	return 0;
}
