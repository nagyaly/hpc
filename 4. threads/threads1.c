#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* routine(void* raw_args){
	int i;
	for(i=0;i<5;i++){
		printf("B: %d\n", i);
		sleep(1);
	}
}
int main(){
	pthread_t tid;
	pthread_create(&tid, NULL, routine, NULL);
	int i;
	for(i=0;i<5;i++){
		printf("A: %d\n", i);
		usleep(1000 * 500);
	}
	pthread_exit(NULL);
	return 0;
}
