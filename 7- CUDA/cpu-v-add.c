#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10
void fill(int* arr, int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = rand() % size;
	}
}
void add_cpu(int* a, int* b, int* c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] + b[i];
	}
}
void display(int* arr, int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
int main(){
	//-------------------	host data allocation
	int *a, *b, *c;
	a = (int *) malloc(sizeof(int) * SIZE);
	b = (int *) malloc(sizeof(int) * SIZE);
	c = (int *) malloc(sizeof(int) * SIZE);
	fill(a, SIZE);
	fill(b, SIZE);
	//-------------------	operation
	add_cpu(a, b, c, SIZE);
	//------------------- 	display
	display(a, SIZE);
	display(b, SIZE);
	display(c, SIZE);
	//-------------------	deallocation
	free(a);
	free(b);
	free(c);
	return 0;
}
