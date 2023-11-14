#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 10e8
void do_work(){
	unsigned long k;
	for(k=0;k<SIZE;k++);
}
int main(){
	int i;
	//make the loop run in prallel
	#pragma omp parallel for num_threads(10)
	for(i=0;i<20;i++){
		printf("%d/10\n", i+1);
		do_work();
	}
	return 0;
}
