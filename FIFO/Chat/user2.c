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
    int fd1 = open("fifo1", O_RDONLY);
    int fd2 = open("fifo2", O_WRONLY);
    char lettura[SIZE];
    char scrittura[SIZE];

    /*printf("Digitare HALT per terminare la chat\n");
    printf("Utente 1: ");
    scanf("%s", scrittura);*/

    do
    {
        read(fd1, lettura, sizeof(lettura));
        printf("Utente 1: %s\n", lettura);
        printf("Utente 2: ");
        scanf("%s", scrittura);
        write(fd2, scrittura, sizeof(scrittura));

    } while (strcmp(scrittura, "HALT"));
    
    close(fd1);
    close(fd2);
    return 0;
}