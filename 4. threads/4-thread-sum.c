#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
float *a, *b, *c;
unsigned int SIZE;
int TCOUNT;
void* routine(void* raw_args){
	int* id = (int*) raw_args;
	unsigned int portion = SIZE / TCOUNT;
	unsigned int start = *id * portion;
	unsigned int end = start + portion;
	unsigned int i;
	printf("Thread %d\t%d->%d\n", *id, start, end);
	for(i=start;i<end;i++){
		c[i] = a[i] * b[i];
	}
}
int main(int argc, char** argv){
	if(argc != 3){
		printf("Invalid Arguments\n");
		return 0;
	}
	SIZE = atoi(argv[1]);
	TCOUNT = atoi(argv[2]);
	printf("SIZE: %d, Threads: %d\n", SIZE, TCOUNT);
	//-------------------------------------------- allocate array
	a = (float*) malloc(sizeof(float) * SIZE);
	b = (float*) malloc(sizeof(float) * SIZE);
	c = (float*) malloc(sizeof(float) * SIZE);
	//-------------------------------------------- fill
	unsigned int i;
	for(i=0;i<SIZE;i++){
		a[i] = -1.0 + rand() / (RAND_MAX / (1.0 - -1.0));
		b[i] = -1.0 + rand() / (RAND_MAX / (1.0 - -1.0));
	}
	//-------------------------------------------- sum sequential
	/*
	clock_t start = clock();
	for(i=0;i<SIZE;i++){
		c[i] = a[i] * b[i];
	}
	clock_t end = clock();
	printf("Elapsed: %.3f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);
	*/
	//-------------------------------------------- parallel
	clock_t start = clock();
	pthread_t tids[TCOUNT];
	int labels[TCOUNT];
	for(i=0;i<TCOUNT;i++){
		labels[i] = i;
		pthread_create(&tids[i], NULL, routine, &labels[i]);
	}
	for(i=0;i<TCOUNT;i++){
		pthread_join(tids[i], NULL);
	}
	clock_t end = clock();
	printf("Elapsed: %.3f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);
	//--------------------------------------------
	free(a);
	free(b);
	free(c);
	return 0;
}
