




//
//learning the exec command 
#include <unistd.h>

main (int argc, char **argv){
	char *av[] = {"ls" , "la" "/" ,0 };

	execvp("ls" ,av);

}
