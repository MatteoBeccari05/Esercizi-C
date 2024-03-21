#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[])
{
    typedef struct
    {
        char nome[30];
        char cognome[30];
        int eta;
        
    } Studente;
    
    int p;
    int fd[2];

    if(pipe(fd)==-1) //apro la pipe
    {
        printf("Errore apertura pipe\n");
        exit(-1);
    }

    p=fork();

    if(p<0) //errore
    {
        printf("Errore apertura fork\n");
        exit(-1);
    }
    else if(p==0) //processo figlio (legge i dati arrivati dal processo padre e li scrive sulla execl)
    {
        close(fd[1]);
        Studente st1letto;
        read(fd[0], &st1letto, sizeof(st1letto));
        char str[20];
        sprintf(str, "%d", st1letto.eta);
        execl("./P2.exe", "P2", st1letto.nome, st1letto.cognome, str, NULL);
        printf("C'è un problema\n");
        close(fd[0]);

    }
    else if(p>0) //processo padre (legge i dati e li passa al processo figlio)
    {
        close(fd[0]);
        Studente st1;
        printf("Inserire il nome: ");
        scanf("%s", st1.nome);
        printf("Inserire la cognome: ");
        scanf("%s", st1.cognome);
        printf("Inserire l'età: ");
        scanf("%d", &st1.eta);
        
        write(fd[1], &st1, sizeof(st1));
        close(fd[1]);
    }


    return 0;
}
