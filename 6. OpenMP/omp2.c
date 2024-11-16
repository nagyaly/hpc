#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 10e6
#define REP 11
void do_work(int id){
//	printf("Id: %d\n", id);
	unsigned long k;
	for(k=0;k<SIZE;k++);
}
int main(){
	int i;
	//create a prallel region
	#pragma omp parallel num_threads(4)
	{
		double time_start = omp_get_wtime();	//get current time
		int tid = omp_get_thread_num();			//get thread id
		int tnum = omp_get_num_threads();		//get number of threads
		//parallize this loop
		#pragma omp for
		for(i=0;i<REP;i++){
			printf("a: %2d/%2d\t%d/%d\n", i+1, REP, tid, tnum);
			do_work(i+1);
		}
		double time_end = omp_get_wtime();		//get current time
		printf("Elapsed of thread %d: %.8f\n", tid, (time_end - time_start));
	}
	return 0;
}
