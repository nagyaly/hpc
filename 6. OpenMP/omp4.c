#include <stdio.h>
#include <omp.h>
int main(){
	unsigned long SIZE = 1e9;
	unsigned long sum = 0;
	unsigned long i;
	#pragma omp parallel num_threads(10) reduction(+:sum)
	{
		#pragma omp for
		for(i=0;i<SIZE;i++){
			//printf("\r%ld/%ld", i,(long) SIZE);
			sum += i;
		}
		printf("Sub Sum: %ld\n", sum);
	}
	printf("TOTAL Sum: %ld\n", sum);
	return 0;
}
