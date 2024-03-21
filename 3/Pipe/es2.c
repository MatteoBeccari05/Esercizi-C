/*Si realizzi un programma C in cui due processi, uno padre e l'altro figlio, interagiscono.
Il processo popola un array di 3 numeri interi (usare il modo che si preferisce per popolare l'array) e li passa al figlio.
Il processo figlio esegue la somma dei numeri passati dal padre e gli restituisce il risultato.
Il processo padre stampa a video il risultato.*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define DIM 3

int main(int argc, char *argv[])
{
    int pid, canale1[2], canale2[2];
    int numeri[] = {1, 2, 3}, somma = 0;

    pipe(canale1);
    pipe(canale2);

    pid = fork();

    if (pid == 0)
    {

        int numeri[DIM];

        close(canale1[1]);
        close(canale2[0]);

        read(canale1[0], numeri, sizeof(numeri));

        for (int i = 0; i < DIM; i++)
        {
            somma = somma + numeri[i];
        }
        printf("FIGLIO: somma %d\n", somma);
        write(canale2[1], &somma, sizeof(somma));

        exit(0);
    }

    close(canale1[0]);
    close(canale2[1]);

    write(canale1[1], numeri, sizeof(numeri));

    read(canale2[0], (void *)&somma, sizeof(somma));
    printf("PADRE: somma %d\n", somma);
    return 0;
}