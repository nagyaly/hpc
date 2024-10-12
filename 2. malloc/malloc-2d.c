#include <stdio.h>
#include <stdlib.h>
int** malloc2D(int size){
	int** arr = (int**) malloc(sizeof(int*) * size);
	int i;
	for(i=0;i<size;i++){
		arr[i] = (int*) malloc(sizeof(int) * size);
	}
	return arr;
}
void free2D(int** arr, int size){
	int i;
	for(i=0;i<size;i++){
		free(arr[i]);
	}
	free(arr);
}
double randFrom(double min, double max){
	double range = max - min;
	return min + rand() / (RAND_MAX / range);
}
int main(int argc, char** argv){
	if(argc != 2){
		printf("Invalid Args\n");
		return -1;
	}
	int size = atoi(argv[1]);
	//----------------------------------------------------------------
	int** a = malloc2D(size);
	int** b = malloc2D(size);
	//----------------------------------------------------------------
	free2D(a, size);
	free2D(b, size);
	return 0;
}
