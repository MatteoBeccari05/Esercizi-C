#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Definizione della struttura libro
struct Libro 
{
    char titolo[50];
    char autore[50];
    float prezzo;
};

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

        // Chiudo il lato di scrittura della pipe nel processo figlio
        close(fd[1]);

        // Leggo i dati dalla pipe
        struct Libro libro1, libro2;
        read(fd[0], &libro1, sizeof(struct Libro));
        read(fd[0], &libro2, sizeof(struct Libro));

        // Stampo i dati ricevuti
        printf("Libro 1:\n");
        printf("Titolo: %s\n", libro1.titolo);
        printf("Autore: %s\n", libro1.autore);
        printf("Prezzo: %.2f\n", libro1.prezzo);

        printf("\nLibro 2:\n");
        printf("Titolo: %s\n", libro2.titolo);
        printf("Autore: %s\n", libro2.autore);
        printf("Prezzo: %.2f\n", libro2.prezzo);

        // Chiudo il lato di lettura della pipe nel processo figlio
        close(fd[0]);

    } 
    else  //padre
    {
        // Chiudo il lato di lettura della pipe nel processo padre
        close(fd[0]);

        // Inizializzo due variabili di tipo libro
        struct Libro libro1 = {"Il Signore degli Anelli", "J.R.R. Tolkien", 25.99};
        struct Libro libro2 = {"1984", "George Orwell", 15.50};

        // Scrivo i dati nella pipe
        write(fd[1], &libro1, sizeof(struct Libro));
        write(fd[1], &libro2, sizeof(struct Libro));

        // Chiudo il lato di scrittura della pipe nel processo padre
        close(fd[1]);

        wait(&status); // Attendo la terminazione del processo figlio
    }

    return 0;
}