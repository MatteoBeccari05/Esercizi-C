#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
    int pid;
    printf("1) prima della fork\n");
    pid = fork();                                   //creo processo figlio 
    printf("2) dopo della fork\n");

    if(pid == 0)
    {
	printf("3) sono il processo figlio con pid %d",getpid());
	printf("il mio papi ha pid %d\n",getppid());
	exit(1);                                    //termina il processo figlio 
    }
    
    else 
    {
	printf("3) sono il processo padre con pid %d",getpid());
	printf("il mio papi ha pid %d\n",getppid());
	exit(0);
    }
}
