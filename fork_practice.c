#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()

{

	fork();
	fork();
	fork();

	fork();
	printf("hello\n\n");

	return 0;

}
