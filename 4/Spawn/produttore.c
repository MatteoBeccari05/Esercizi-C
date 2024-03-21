#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 1024
#define PROGRAM "./consumatore.exe"

int spawn(char program[], char* argument[])
{
    int p;
    printf("Sono il padre spawn, il mio pid è: %d\n", getpid());

    p = fork;
    if(p<0)
    {
        return -1;
    }
    if(p>0)
    {
        printf("Sono il padre spawn, mio figlio ha pid: %d\n", p);
    }
    if(p==0)
    {
        printf("Sono il figlio spawn, il mio pid è: %d\n", getpid());
    }

    execv(program, argument);

    printf("Problema nella execv\n");
    abort();
}


int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[SIZE];
    int n;
    char *arg[3];
    int a;

    printf("Sono padre main ossia il processo produttore, il mio pid è: %d\n", getpid());

    if(argc != 3)
    {
        printf("Errore apertura file\n");
        return 0;
    }

    arg[0] = (char*)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);

    arg[1] = (char*)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);

    arg[2] = NULL;

    if(spawn(PROGRAM, arg) < 0)
    {
        printf("\nErrore nella creazione del figlio");
        free(arg[0]);
    }
    return 0;
}