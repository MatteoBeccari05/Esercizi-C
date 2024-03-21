#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>  //serve per aprire la fifo

#define MAX 5

int main()
{
    //Dichiarazione delle variabili
    int fd;
    int numeri[MAX];
    int somma;
    
    fd = open("sum", O_RDONLY);  
    printf("Ho aperto la FIFO");

    for(int i = 0; i<MAX ; i++)
    {
        if(read(fd, &numeri[i], sizeof(numeri[i])) == -1);  //controllo che la read sia andata a buon fine
        {
            printf("\nErrore lettura dalla FIFO\n");
            return 2;
        }
        somma += numeri[i];

    }
    printf("La somma è: %d", somma);
    
    close(fd);  //chiudo la FIFO    

    return 0;
}