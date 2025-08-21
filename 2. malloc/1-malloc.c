#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	if(argc != 2){
		printf("Invalid Args\n");
		return -1;
	}
	int size = atoi(argv[1]);
	printf("%d\n", size);
	//int arr[size];
	int *arr = (int*)malloc(sizeof(int) * size);
	int i;
	for(i=0;i<size;i++){
		printf("%p\n", arr + i);
	}
	free(arr);
	return 0;
}
