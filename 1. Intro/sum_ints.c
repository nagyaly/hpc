#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randIntFrom(int min, int max){
	return min + rand() % (max - min + 1);
}
int main(int argc, char** argv){
	if(argc != 2){
		perror("Invalid Args\n");
		return 1;
	}
	//-----------------------------------------------------------------------------------
	clock_t t_start = clock();
	unsigned long SIZE = atoi(argv[1]);
	int* arr = (int*) malloc(sizeof(int) * SIZE);
	printf("Elapsed Allocation: %.6f\n", (double)(clock() - t_start) / CLOCKS_PER_SEC);
	//-----------------------------------------------------------------------------------
	t_start = clock();
	unsigned long int i;
	unsigned long int sum = 0;
	for(i=0;i<SIZE;i++){
		arr[i] = randIntFrom(0, 10);
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
	printf("\nSUM: %ld\n", sum);
	free(arr);
	return 0;
}
