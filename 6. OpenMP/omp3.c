#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SIZE 10e6
#define REP 1000
void do_work(int id){
	int tid = omp_get_thread_num();
	int tnum = omp_get_num_threads();

	double time_start = omp_get_wtime();
	//do some work
	unsigned long k;
	for(k=0;k<SIZE;k++);

	double time_end = omp_get_wtime();
//	printf("Task: %2d/%2d\tThread: %d/%d\tTime: %.8f\n", id, REP, tid, tnum, (time_end - time_start));
}
int main(){
	int i;
	//create a prallel region
	#pragma omp parallel num_threads(80)
	{
		int tid = omp_get_thread_num();
		int tnum = omp_get_num_threads();
		double time_start = omp_get_wtime();
		//parallize this loop
		#pragma omp for
		for(i=0;i<REP;i++){
			do_work(i+1);
		}
		double time_end = omp_get_wtime();
		printf("Thread: %d/%d\tTime: %.8f\n", tid, tnum, (time_end - time_start));
	}
	return 0;
}
