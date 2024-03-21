#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int fd[2];
    int p;
    int status;

    int t;
    printf("Quanti numeri vuoi inserire nell'array? Scelta: ");
    scanf("%d", &t);
    if (pipe(fd) == -1) 
    {
        perror("Errore nella creazione della pipe\n");
        exit(-1);
    }

    // Creazione del processo figlio
    p = fork();

    if (p == -1) 
    {
        perror("Errore nella creazione del processo figlio\n");
        exit(-1);
    }
    

    if(p==0) //figlio
    {
        
        close(fd[1]);
        int moltiplicatore;
        int numeriLetti[t];
        read(fd[0], numeriLetti, sizeof(numeriLetti));
        close(fd[0]);
        int somma;
        for(int i = 0; i<t; i++)
        {
            somma += numeriLetti[i];
        }
        printf("Somma: %d\n", somma);

        printf("\nInserire il moltiplicatore: ");
        scanf("%d", &moltiplicatore);

        for(int i = 0; i<t; i++)
        {
            printf("Numero %d: %d\n", i+1, numeriLetti[i]*moltiplicatore);
        }
    }
    else
    {
        close(fd[0]);
        int array[t];

        for(int i = 0; i<t; i++)
        {
            printf("Inserire numero %d: ", i+1);
            scanf("%d", &array[i]);
        }
        write(fd[1], array, sizeof(array));
        close(fd[1]);
        wait(&status);
    }
    return 0;
}