#include <stdio.h>
#include <stdlib.h>
/*
	to compile:		gcc pass_args.c -o pass_args
	to run:			./pass_args
	to run with 1 args	./pass_args 10
	to run with many args	./pass_args 10 20 30....
*/
int main(int argc, char** argv){
	//argc represent the number of arguments
	//argv is array of strings (contain the arguments)
	//note: first element in argv is the file name "./pass_args"
	if(argc != 2){
		printf("Invalid Args\n");
		return -1;
	}
	//convert string in argv[1] to int
	int x = atoi(argv[1]);
	printf("%d\n", x);
	return 0;
}
