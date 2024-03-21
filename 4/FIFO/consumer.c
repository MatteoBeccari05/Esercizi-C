#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Numero argomenti sbagliato");
        exit(-1);
    }
    
    int fd;
    int somma=0;
    char buffer[BUFFER_SIZE];
    fd = open("fifo", O_RDONLY);

    FILE *destinazione = fopen(argv[1], "wr");
    if (!destinazione) 
    {
        printf("Errore apertura file destinazione");
        exit(-1);
    }

    int n;

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) 
    {
        fwrite(buffer, 1, n, destinazione);
    }
    fclose(destinazione);
    close(fd);
    return 0;
    
}