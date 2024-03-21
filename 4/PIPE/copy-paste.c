#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *sorgente;
    FILE *destinazione;
    int fd[2];
    int status;
    int p;

    if(argc!= 3)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

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

    if (p == 0) //figlio
    {
        wait(&status);
        close(fd[1]);
        destinazione = fopen(argv[2], "wb");

        if (!destinazione) 
        {
            printf("Errore apertura file destinazione");
            exit(-1);
        }

        char buffer[BUFFER_SIZE];
        int n;

        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0) 
        {
            fwrite(buffer, 1, n, destinazione);
        }

        close(fd[0]);

        fclose(destinazione);
    }
    else //padre
    {
        close(fd[0]); 
        sorgente = fopen(argv[1], "rb");
        
        if (!sorgente) 
        {
            printf("Errore apertura file sorgente");
            exit(-1);
        }

        char buffer[BUFFER_SIZE];
        int n;

        while ((n = fread(buffer, 1, sizeof(buffer), sorgente)) > 0) 
        {
            write(fd[1], buffer, n);
        }

        close(fd[1]); 

        fclose(sorgente);

    }
    return 0;

}