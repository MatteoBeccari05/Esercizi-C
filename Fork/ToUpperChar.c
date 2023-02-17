/*Si scriva un programma in C che legge in input da argv[1] un carattere, quindi istanzi un processo figlio
il quale deve convertire il carattere in maiuscolo e terminare. Il padre attende la terminazione del processo figlio.*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int pid:             
    int st;

    pid=fork();       //eseguo la fork 

    if(pid<0)
    {
        exit(1);         //se il pid ritorna un errore esco dal programma
    }

    if(pid==0)
    {
        printf("il carattere %c in maiuscolo è: %c", argv[1][0], toupper(argv[1][0]));      //scrivo il carattere in maiuscolo 
        exit(0);
    }
    else
    {
        wait(&st);        //metto in wait il padre finchè il figlio termina 
    }
}