#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 5
int p;

int main() 
{
    // Creazione della pipe
    int fd[2];
    int status;
    if (pipe(fd) == -1) 
    {
        perror("Errore nella creazione della pipe");
        exit(-1);
    }

    // Creazione del processo figlio
    p = fork();

    if (p == -1) 
    {
        perror("Errore nella creazione del processo figlio");
        exit(-1);
    }

    if (p == 0) //figlio
    {

        int numeri[DIM];

        // Richiesta all'utente di inserire cinque numeri
        printf("Inserisci cinque numeri:\n");
        for (int i = 0; i < DIM; i++) 
        {
            printf("Numero %d: ", i + 1);
            scanf("%d", &numeri[i]);
        }

        // Chiusura del lato di scrittura della pipe nel processo figlio
        close(fd[0]);

        // Scrittura dell'array nella pipe
        write(fd[1], numeri, sizeof(numeri));

    } 
    else //padre
    {
        wait(&status);
        int numeri_ricevuti[DIM];
        int moltiplicatore;

        // Chiusura del lato di scrittura della pipe nel processo padre
        close(fd[1]);

        // Richiesta all'utente del moltiplicatore
        printf("Inserisci il moltiplicatore: ");
        scanf("%d", &moltiplicatore);

        // Lettura dell'array dalla pipe
        read(fd[0], numeri_ricevuti, sizeof(numeri_ricevuti));

        // Stampa dei numeri moltiplicati
        printf("Numeri ricevuti e moltiplicati:\n");
        for (int i = 0; i < DIM; i++) 
        {
            printf("Numero %d: %d  \n",i + 1, numeri_ricevuti[i] * moltiplicatore);
        }
        printf("\n");
    }

    return 0;
}