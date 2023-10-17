#include <stdio.h>
#include <stdlib.h>
#include <time.h>
double randFrom(double min, double max){
	double range = max - min;
	return min + rand() / (RAND_MAX / range);
}
int main(int argc, char** argv){
	if(argc != 2){
		perror("Invalid Args\n");
		return 1;
	}
	//-----------------------------------------------------------------------------------
	clock_t t_start = clock();
	unsigned long SIZE = atoi(argv[1]);
	double* arr = (double*) malloc(sizeof(double) * SIZE);
	printf("Elapsed Allocation: %.6f\n", (double)(clock() - t_start) / CLOCKS_PER_SEC);
	//-----------------------------------------------------------------------------------
	t_start = clock();
	unsigned long i;
	double sum = 0;
	for(i=0;i<SIZE;i++){
		arr[i] = randFrom(-1.0, 1.0);
	}
	printf("Elapsed Fill: %.3f\n", (double)(clock() - t_start) / CLOCKS_PER_SEC);
	//-----------------------------------------------------------------------------------
	//for(i=0;i<SIZE;i++){
	//	printf("%.2f ", arr[i]);
	//}
	t_start = clock();
	for(i=0;i<SIZE;i++){
		sum += arr[i];
	}
	printf("Elapsed SUM: %.3f\n", (double)(clock() - t_start) / CLOCKS_PER_SEC);
	//-----------------------------------------------------------------------------------
	printf("\nSUM: %.3f\n", sum);
	free(arr);
	return 0;
}
