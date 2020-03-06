#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main ( int argc , char **argv)
{
    fork();
    fork();
    
    sleep(10000);
    exit(0);
}