#include <stdio.h>
#include <omp.h>
int main(){
	unsigned long SIZE = 10e8;
	unsigned long sum = 0;			//reduced variable...
	unsigned long i;
	#pragma omp parallel num_threads(10) reduction(+:sum)
	{
	    int tid = omp_get_thread_num();
		int tnum = omp_get_num_threads();
		double time_start = omp_get_wtime();
		#pragma omp for
		for(i=0;i<SIZE;i++){
			//printf("\r%ld/%ld", i,(long) SIZE);
			sum += i;
		}
		double time_end = omp_get_wtime();
		printf("Thread %2d/%2d \t Sub Sum: %ld \t %.8f sec\n", tid, tnum, sum, (time_end - time_start));
	}
	printf("TOTAL Sum: %ld\n", sum);
	return 0;
}
