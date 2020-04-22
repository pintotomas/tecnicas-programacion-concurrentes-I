
#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main() 
{ 
    for(int i=0;i<10;i++) // loop will run n times (n=5) 
    { 
        if(fork() == 0) 
        { 
            srand(time(NULL) ^ (getpid()<<16));
            int random_ammount = rand() % 8;
            sleep(random_ammount); 
            exit(random_ammount); 
        } 
    } 
    pid_t wpid;
    int status;
    while ((wpid = wait(&status)) > 0)
    {
        printf("Waittime for child %d is %d\n", wpid ,status/255); 
    }
    ; //Para que el padre espere por todos sus hijos 
} 

