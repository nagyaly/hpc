#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
/*
	5 theads	2,2,2,2,2		-> 2*3sec = 6 sec
	6 threads	2,2,2,2,2,1		-> 2*3sec = 6 sec
	9 threads	2,2,2,2,2,2,2,1		-> 2*3sec = 6 sec
	10 threads	1,1,1,1,1,1,1,1,1,1	-> 1*3sec = 3 sec
*/
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
	#pragma omp parallel for num_threads(5)
	for(i=0;i<10;i++){
		printf("%d/10\n", i+1);
		do_work();
	}
	return 0;
}
