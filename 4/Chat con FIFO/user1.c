#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

#define SIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = open("fifo1", O_WRONLY);
    int fd2 = open("fifo2", O_RDONLY);
    char lettura[SIZE];
    char scrittura[SIZE];
    FILE *log = fopen("log.txt", "wr");

    printf("Digitare HALT per terminare la chat\n");
    printf("Utente 1: ");
    //scanf("%s", scrittura);
    fgets(scrittura, sizeof(scrittura), stdin);

    do
    {
        write(fd1, scrittura, sizeof(scrittura));  //invio il messaggio alla fifo 
        fprintf(log, "Utente 1: %s\n", scrittura);
        read(fd2, lettura, sizeof(lettura));        //leggo il messaggio che arriva 
        fprintf(log ,"Utente 2: %s\n", lettura);
        printf("Utente 2: %s\n", lettura);
        printf("Utente 1: ");
        //scanf("%s", scrittura);
        fgets(scrittura, sizeof(scrittura), stdin);
        
    } while (strcmp(scrittura, "HALT"));
    
    close(fd1);
    close(fd2);
    return 0;
}