#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) 
{
    int p;
    int status;
    int fd[2];
    if (argc != 3) 
    {
        printf("Numero argomenti sbagliato");
        exit(-1);
    }

    if (pipe(fd) == -1) 
    {
        printf("Pipe non riuscita");
        exit(-1);
    }

    p = fork();

    if (p == -1) 
    {
        printf("Fork non riuscita");
        exit(-1);
    }

    if (p > 0) 
    {  
        close(fd[0]); 

        FILE *sorgente = fopen(argv[1], "rb");
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

        wait(&status); 
    } 
    else 
    {
        close(fd[1]); 

        FILE *destinazione = fopen(argv[2], "wb");
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

    return 0;
}