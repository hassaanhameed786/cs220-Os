#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main ( int argc , char **argv) 
{
    int pid;
    pid = fork();
    if(pid == -1)
    {
        perror("ERROR");
    }
    
        if (pid == 1)
        {   
            printf("Child fork called %d\n" , getpid());
        }

        else if ( pid == 0)
        {   //fork();
             //fork();
            //fork();
            //fork();
           
            printf("Parent fork is called %d\n", getppid());
            printf("is it child ? %d\n",  getpid() );
            
        }
        
        

    sleep(1);
    exit(0);
}