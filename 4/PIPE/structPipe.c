#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define DIM 2

// Definizione della struttura libro
typedef struct 
{
    char titolo[50];
    char autore[50];
    float prezzo;
} Libro ;

int main() 
{
    int p;
    int status;
    // Creazione della pipe
    int fd[2];
    if (pipe(fd) == -1) 
    {
        perror("Errore nella creazione della pipe");
        exit(-1);
    }

    // Creazione del processo figlio
    p = fork();

    if (p == -1) {
        perror("Errore nella creazione del processo figlio");
        exit(-1);
    }

    if (p == 0)  //figlio
    {
        Libro array[DIM];

        // chiuso scrittura
        close(fd[1]);

        // lettura pipe
        read(fd[0], array, sizeof(array));

        // stampa dati
        for (int i = 0; i < DIM; i++)
        {
            printf("Titolo:  %s  \n", array[i].titolo);
            printf("Autore:  %s \n", array[i].autore);
            printf("Prezzo:  %.2f \n", array[i].prezzo);
        }

        // chiusura pipe
        close(fd[0]);

    } 
    else  //padre
    {
        // Chiudo il lato di lettura della pipe nel processo padre
        close(fd[0]);
        Libro array[DIM];
        
        for(int i = 0; i < DIM; i++)
        {
            printf("Inserire il titolo: ");
            scanf("%s", array[i].titolo);
            printf("Inserire l'autore: ");
            scanf("%s", array[i].autore);
            printf("Inserire il prezzo: ");
            scanf("%f", &array[i].prezzo);
        }
        
        // Scrivo i dati nella pipe
        write(fd[1], array, sizeof(array));

        close(fd[1]);
    }

    return 0;
}