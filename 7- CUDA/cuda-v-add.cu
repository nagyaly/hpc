#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10
/*
	to compile:
		submit.nvcc cuda-v-add.cu -o cuda-v-add
*/
//kernel function, will be loaded into the GPU (device)
__global__ void add_gpu(int* a, int* b, int* c, int size){
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if( i < size ){				//if thread id exceed the array size....
		c[i] = a[i] + b[i];
	}
}
void add_cpu(int* a, int* b, int* c, int size){
	int i;
	for(i=0;i<size;i++){
		c[i] = a[i] + b[i];
	}
}
void fill(int* arr, int size){
	int i;
	for(i=0;i<size;i++){
		arr[i] = rand() % size;
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
	//-------------------	device setup
	int *d_a, *d_b, *d_c;
	//allocate memory in device
	cudaMalloc((void **)&d_a, sizeof(int) * SIZE);
	cudaMalloc((void **)&d_b, sizeof(int) * SIZE);
	cudaMalloc((void **)&d_c, sizeof(int) * SIZE);
	//copy input data from host to device
	cudaMemcpy(d_a, a, sizeof(int) * SIZE, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, sizeof(int) * SIZE, cudaMemcpyHostToDevice);
	//setup grid dim, and block dim
	int threads_per_block = (SIZE > 512) ? 512 : SIZE;
	int blocks_per_grid = ceil(SIZE / (double)threads_per_block);
	printf("GridDim: %d\tBlockDim: %d\n", blocks_per_grid, threads_per_block);
	//call the kernel function
	add_gpu<<<blocks_per_grid, threads_per_block>>>(d_a, d_b, d_c, SIZE);
	//copy output data from device to host
	cudaMemcpy(c, d_c, sizeof(int) * SIZE, cudaMemcpyDeviceToHost);

	display(c, SIZE);
	//-------------------	deallocation
	free(a);
	free(b);
	free(c);
	return 0;
}
