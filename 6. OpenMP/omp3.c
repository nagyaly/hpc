#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#define TASKS 20
void do_work(int id){
	int tid = omp_get_thread_num();
	int tnum = omp_get_num_threads();

	double time_start = omp_get_wtime();
	//do some work
	int k;
	for(k=0;k<5;k++) sleep(1);

	double time_end = omp_get_wtime();
	printf("Task: %2d/%2d\tThread: %d/%d\tTime: %.8f\n", id, TASKS, tid, tnum, (time_end - time_start));
}
int main(){
	int i;
	//create a prallel region
	#pragma omp parallel num_threads(6)
	{
		int tid = omp_get_thread_num();
		int tnum = omp_get_num_threads();
		double time_start = omp_get_wtime();
		//parallize this loop
		#pragma omp for
		for(i=0;i<TASKS;i++){
			do_work(i+1);
		}
		double time_end = omp_get_wtime();
		printf("Thread: %d/%d\tTime: %.8f\n", tid, tnum, (time_end - time_start));
	}
	return 0;
}
