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

    }
    else if(pid > 0){
         printf("\n\n");

         printf("I'm Parent process and my PID = %d\n" ,getpid() );
         printf("My Child PID =%d\n", pid);

         // now kill the process use the kill [options] <pid> [...]
        kill(pid, SIGTERM);
        sleep(120);  
    }
    else {
        printf("Error :( not aa gya ha ");

    }
}