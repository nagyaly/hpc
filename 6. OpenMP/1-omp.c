#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
void do_work(){
	int k;
	for(k=0;k<3;k++){
		printf("%d\n", k);
		sleep(1);
	}
}
int main(){
	int i;
	//make the loop run in prallel
	#pragma omp parallel for num_threads(1)
	for(i=0;i<10;i++){
		printf("%d/10\n", i+1);
		do_work();
	}
	return 0;
}
