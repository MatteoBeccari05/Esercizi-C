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
    // Stampa dei dati ricevuti da P1
    printf("\n--------------------------------------\n");
    printf("Dati dello studente ricevuti da P1:\n");
    printf("Nome: %s\n", argv[1]);
    printf("Cognome: %s\n", argv[2]);
    printf("Età: %s\n", argv[3]);
    
    return 0;
}
