#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    int pid = fork(); // child and parent process created 
    
    if (pid == 0){
        printf("\n\n");

        printf("I'm Child process and my PID = %d\n" ,getpid() );
        printf("My parent PID =%d\n",getpid());

        // now in this piece of code we use kill parent process
        kill(getpid(),SIGTERM);
        sleep(120);

    }
    else if(pid > 0){
         printf("\n\n");

         printf("I'm Parent process and my PID = %d\n" ,getpid() );
         printf("My Child PID =%d\n", pid);
    }
    else {
        printf("Error :( not aa gya ha ");

    }
}