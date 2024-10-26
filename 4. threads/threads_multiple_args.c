#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define SIZE 3
typedef struct {
	char label;
	int start, end;
} Targs;
void* routine(void* raw_args){
	Targs* args = (Targs*) raw_args;		//explicit type casting
	int i;
	for(i=args->start;i<args->end;i++){
		printf("%c: %d/%d/%d\n", args->label, args->start+1, i+1, args->end);
		//sleep(1);
	}
}
int main(){
	int i;
	pthread_t tids[SIZE];
	Targs args[SIZE];
	for(i=0;i<SIZE;i++){
		args[i].label = 'A' + i;
		args[i].start = 1 + rand() % 10;
		args[i].end = args[i].start + 1 + rand() % 10;
		pthread_create(&tids[i], NULL, routine, &args[i]);
	}
	for(i=0;i<5;i++){
		printf("main: %d\n", i);
		//usleep(1000 * 500);
	}
	pthread_exit(NULL);
	return 0;
}
