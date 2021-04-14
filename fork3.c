
//practice the fork sys call 

#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()

{
	int pid;

	pid = fork();

	// let say if child PID ==0
	if(pid ==0){


		fork();
		fork();

		printf("i m the child\n\n");
	}
	else
	
		fork();

		printf("I m the parent\n\n");
}

