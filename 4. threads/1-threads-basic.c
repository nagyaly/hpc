#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
void* routine(void* raw_args){
	int i;
	for(i=0;i<5;i++){
		printf("child: %d\n", i);
		sleep(1);			//seconds
	}
}
int main(){
	pthread_t tid;					//id for the thread
	pthread_create(&tid, NULL, routine, NULL);	//thread id, attr, routine, args
	int i;
	for(i=0;i<5;i++){
		printf("main: %d\n", i);
		usleep(0.2 * 1e6);		//micro seconds
	}
	pthread_exit(NULL);			//parent will wait for child
	//pthread_join(tid, NULL);			//wait for specific thread
	return 0;
}
