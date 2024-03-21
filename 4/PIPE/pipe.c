#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

// int fd[2]; => array di due interi
// pipe(fd); => eseguo la pipe

int main(int argc, char *argv[])
{
    int fd[2];
    int p;
    int n;
    char buffer[BUFFER_SIZE];

    if(pipe(fd) == -1)  //creazione della pipe
    {
        printf("Errore nella pipe");
        exit(-1);
    }

    p = fork();
    if(p<0)
    {
        printf("\nErrore nella fork");
        exit(-1);
    }

    if(p>0) //padre
    {
        printf("\nSono il padre: il mio PID: %d - mio figlio ha PID: %d", getpid(), p);
        close(fd[0]);  //il padre scrive e chiude in lettura
        const char *messaggio = "Buona fortuna";  //messaggio che il padre manderà al figlio tramite la pipe

        if(write(fd[1], messaggio, strlen(messaggio))== -1)  //eseguo la write in fd[1]
        {
            printf("\nWrite non riuscita");
            exit(-1);
        }
        close(fd[1]);
       
    }
    else //figlio
    {
        printf("\nSono il figlio: il mio PID: %d - mio padre ha PID: %d", getpid(), getppid());
        close(fd[1]);   //il figlio legge e chiude in scrittura

        n=read(fd[0], buffer, BUFFER_SIZE);  //leggo il messaggio dal buffer
        if(n == -1)
        {
            printf("\nREad non riuscita");
            exit(-1);
        }
        else
        {
            buffer[n] = '\0';
            printf("\nMessaggio ricevuto: %s\n", buffer);  //stampo il messaggio
        }
    }


    return 0;
}