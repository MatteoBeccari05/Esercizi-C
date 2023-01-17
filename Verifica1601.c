#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd, n;
    char buf;


    int pid;
    pid = fork();                                 //crea un processo figlio

    int wait(int *status);                      //Sospende il processo corrente finché un figlio non ha terminato di eseguire.

    void exit(int status)                       //chiude tutti i file descriptor appartenenti al processo

    void close(int fd)                          //chiude il file

    int read(int fd, char* buf, int n)          //legge un fllusso di dati dal file descriptor

    int open(const char *pathname, int flags, mode_t)   //apre un file

    int write(int fd, char* buf, int n)         //scrive su un file

}


