#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#define REP 11
void do_work(int id){
//	printf("Id: %d\n", id);
	int k;
	for(k=0;k<5;k++) sleep(1);
}
int main(){
	int i;
	//create a prallel region
	#pragma omp parallel num_threads(3)
	{
		double time_start = omp_get_wtime();	//get current time
		int tid = omp_get_thread_num();			//get thread id
		int tnum = omp_get_num_threads();		//get number of threads
		//parallize this loop
		#pragma omp for
		for(i=0;i<REP;i++){
			printf("a: %2d/%2d\t%d/%d\n", i+1, REP, tid+1, tnum);
			do_work(i+1);
		}
		double time_end = omp_get_wtime();		//get current time
		printf("Elapsed of thread %d: %.8f\n", tid, (time_end - time_start));
	}
	return 0;
}
