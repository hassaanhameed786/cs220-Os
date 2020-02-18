// Fork is used to create child 
//Fork calls the clone functior n 

// go to terminal and check out (man fork --> details of fork ())
#include <stdio.h>
#include < unisted.h>


int int main(void) {

     int ret;   //PID
     ret = fork()
     if ( ret > 0)
     {
         printf( "\n i am a parent");
         printf( "\n MY pid is %d", getpid());
     }
     else if (ret == 0)
     {
         printf( "\n i am a child");
         printf( "\n MY pid is %d", getpid());
         printf( "\n MY  parent pid is %d", getppid());

     }
     
	return 0;
    
}

/* 


fork ();   // Line 1
fork ();   // Line 2
fork ();   // Line 3

       L1       // There will be 1 child process 
    /     \     // created by line 1.
  L2      L2    // There will be 2 child processes
 /  \    /  \   //  created by line 2
L3  L3  L3  L3  // There will be 4 child processes 
                // created by line 3
		*/
