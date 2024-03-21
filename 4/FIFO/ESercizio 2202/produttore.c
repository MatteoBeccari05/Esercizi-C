#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>  //serve per aprire la fifo
#include <time.h>

#define MAX 5

int main(int argc, char *argv[])
{
    //Dichiarazione delle variabili
    
    int fd;
    int numeriCasuali[MAX];
    int numero;
    
    //Creazione della FIFO
    if(mkfifo("sum", 0777) == -1)   //mkfifo(nomeFifo, permessi)
    {
        if(errno != EEXIST)
        {
            printf("\nErrore nella creazione della FIFO\n");
            return 1;
        }
    }  
    fd = open("sum", O_WRONLY);  
    printf("Ho aperto la FIFO");
    

    srand(time(NULL));
    // Generazione e inserimento dei numeri casuali nell'array
    for (int i = 0; i < MAX; i++) 
    {
        numero = rand() % 100;
        numeriCasuali[i] = numero; // Genera un numero casuale tra 0 e 99
        if(write(fd, &numeriCasuali[i], sizeof(numeriCasuali[i])) == -1);  //controllo che la write sia andata a buon fine
        {
            printf("\nErrore scrittura nella FIFO\n");
            return 2;
        }
    }
    
    printf("Ho scritto nella FIFO\n");
    close(fd);  //chiudo la FIFO    

    return 0;
}
