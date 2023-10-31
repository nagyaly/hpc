#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 3
void* routine(void* raw_args){
	char* args = (char*) raw_args;		//explicit type casting
	int i;
	for(i=0;i<5;i++){
		printf("%c: %d\n", *args, i);
		//sleep(1);
	}
}
int main(){
	int i;
	pthread_t tids[SIZE];
	char labels[SIZE];
	for(i=0;i<SIZE;i++){
		labels[i] = 'A' + i;
		pthread_create(&tids[i], NULL, routine, &labels[i]);
	}
	for(i=0;i<5;i++){
		printf("main: %d\n", i);
		//usleep(1000 * 500);
	}
	pthread_exit(NULL);
	return 0;
}
