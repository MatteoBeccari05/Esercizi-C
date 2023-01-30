#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int main()
{
    int pid1, pid2, pid3;
    printf("1) prima della fork\n");
    pid1  = fork();      
    pid2  = fork(); 
    pid3  = fork();                              //creo processo figlio 

    if((pid1 == 0) || (pid2==0) || (pid3==0))   //se uno è 0 è un figlio 
    {
	printf("Sono il processo figlio con pid %d. ",getpid());
	printf("il mio papi ha pid: %d\n",getppid());
        sleep(1);                                   //attesa per non creare orfani 
	exit(1);                                    //termina il processo figlio 
    }
    
    else 
    {
        sleep(2);
	printf("Sono il processo padre con pid: %d\n",getpid());
    }
    return 0;
}
