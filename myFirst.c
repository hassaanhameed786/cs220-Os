#include<stdio.h>
#include<stdlib.h>
void main()
{
printf("\nThis is C Programming in Ubuntu\n\n");
printf("\nHere in this program we will run linux commands\n\n");
system("ls -l");
printf("\nenter the name\n\n");
scanf("enter a username");
// this command will print all the contents of current directory in long format.


printf("------------------------------------------------------------------------------------" );

printf("here we would play with the system function()" );

system("mkdir ali");
system("mkdir usman");
system("touch test1.txt test2.txt");
printf(" display the contents of that file of myFirst.c\n\n\n\n");
system("cat tes1.txt");
system("rm -d test");

}
