#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main ( int argc , char **argv) 
{
	printf("my process ID is %d\n" , getpid() );
	printf("my parent Process ID is %d\n" , getppid() );
	exit(0);

}
