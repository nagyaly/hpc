#include <stdio.h>
#include <time.h>

int main(){
	unsigned long i, sum = 0;
	clock_t start_t, end_t;
        end_t = clock();
	for(i=0;i<10e7;i++){
		sum += i % 10;
	}
        end_t = clock();
	printf("RESULT: %ld\n", sum);
        printf("%.3f msec\n", (end_t - start_t) * 1000.0 / CLOCKS_PER_SEC);
	return 0;
}
