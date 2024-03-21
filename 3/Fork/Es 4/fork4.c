#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{ 
    int pid;
    int uguale, diversa;
    uguale  = 10;
    diversa = 10;
    printf( "1) prima della fork \n" );
    pid = fork();                            // creo processo figlio 
    printf( " 2) dopo della fork \n" );
    if (pid == 0)
    {
        diversa = 20;
        printf( " 3) sono il processo figlio con pid: %d\n", getpid() );
        printf( " 4) la mia variabile uguale contiene : %d\n", uguale);
        printf( " 5) sono il processo diversa contiene: %d\n", diversa);
        exit(1) ;                              // termina il processo figlio 
    }
    else
    {
        diversa = 30;
        printf( " 3) sono il processo padre pid: %d\n", getpid()) ;
        printf( " 4) la mia variabile uguale contiene : %d\n", uguale);
        printf( " 5) sono il processo diversa contiene: %d\n", diversa);
        exit(0) ;                              // non necessaria
    }
    return 0;
}