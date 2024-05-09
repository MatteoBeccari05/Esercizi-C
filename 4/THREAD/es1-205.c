#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define ARRAY_SIZE 1000
#define MIN_VALUE 1
#define MAX_VALUE 500 

//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*-creare un array di mille numeri con valori compresi nell'intervallo 1-500;
-ricercare un numero inserito nell'array distribuendo in maniera equa il carico di lavoro a quattro processi;
- se il numero è nell'array stampare la posizione, altrimenti stampare "numero non trovato".*/


typedef struct
{
    int numeroDaCercare;
    int array[ARRAY_SIZE];
    int inizio;
    int fine;
} Ricerca;

void* PrimaMeta(void* par)   //la firma è obbligatoriamente così
{
    int contatore = 0;
    Ricerca r1 = *(Ricerca *)par;
    for(int i = r1.inizio; i<r1.fine; i++)
    {
        if(r1.array[i] == r1.numeroDaCercare)
        {
            printf("Il numero %d è stato trovato in posizione %d\n", r1.numeroDaCercare, i+1);
            contatore++;
        }
    }
    if(contatore == 0)
    {
        printf("Numero non trovato\n");
    }
    return (void*)0;
}

int main()
{
    pthread_t primo, secondo, terzo, quarto;
    Ricerca r1;

    for (int i = 0; i < ARRAY_SIZE; i++) 
    {
        r1.array[i] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
    }

    printf("Inserire il numero da ricercare: ");
    scanf("%d", &r1.numeroDaCercare);

    r1.inizio = 0;
    r1.fine = ARRAY_SIZE/4;
    pthread_create(&primo, NULL, &PrimaMeta, (void*)&r1);   //creo un thread

    r1.inizio = ARRAY_SIZE/4;
    r1.fine = ARRAY_SIZE/2;
    pthread_create(&secondo, NULL, &PrimaMeta, (void*) &r1);   //creo un thread

    r1.inizio = ARRAY_SIZE/2;
    r1.fine = ARRAY_SIZE - (ARRAY_SIZE/4);
    pthread_create(&terzo, NULL, &PrimaMeta, (void*)&r1);   //creo un thread

    r1.inizio = ARRAY_SIZE - (ARRAY_SIZE/4);
    r1.fine = ARRAY_SIZE;
    pthread_create(&quarto, NULL, &PrimaMeta, (void*) &r1);   //creo un thread

    //Attendo che i 2 thread terminino la loro esecuzione
    pthread_join(primo, NULL);
    pthread_join(secondo, NULL);
    pthread_join(terzo, NULL);
    pthread_join(quarto, NULL);

    return 0;
}