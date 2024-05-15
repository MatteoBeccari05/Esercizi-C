#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

#define SIZE 10
//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*Creare un programma che:
1 - crea un array di 10 numeri (tra questi inserire il numero otto in una posizione qualsiasi);
2 - crea un thread per ricercare il numero otto nella prima metà dell'array;
3 - crea un altro thread per ricercare il numero otto nella seconda metà dell'array.
Il thread che trova il numero otto deve stampare la posizione che occupa nell'array.*/


typedef struct
{
    int numeroDaCercare;
    int array[10];
} Ricerca;

void* PrimaMeta(void* par)   //la firma è obbligatoriamente così
{
    Ricerca *r1 = (Ricerca *)par;
    for(int i = 0; i<SIZE/2; i++)
    {
        if(r1->array[i] == r1->numeroDaCercare)
        {
            printf("Il numero %d è stato trovato nella posizione %d\n", r1->numeroDaCercare, i);
        }
    }
    return (void*)0;
}

void* SecondaMeta(void* par)  
{
    Ricerca *r1 = (Ricerca *)par;
    for(int i = SIZE/2; i<SIZE; i++)
    {
        if(r1->array[i] == r1->numeroDaCercare)
        {
            printf("Il numero %d è stato trovato nella posizione %d\n", r1->numeroDaCercare, i);
        }
    }
    return (void*)0;
}

int main()
{
    pthread_t primo, secondo;
    Ricerca r1;

    int i;
    for(i=0;i<SIZE;i++)
    {
        printf("Inserisci il %d numero: ",(i+1));
        scanf("%d",&r1.array[i]);
    }

    printf("Inserire il numero da ricercare: ");
    scanf("%d", &r1.numeroDaCercare);

    pthread_create(&primo, NULL, &PrimaMeta, (void*)&r1);   //creo un thread
    pthread_create(&secondo, NULL, &SecondaMeta, (void*) &r1);   //creo un thread

    //Attendo che i 2 thread terminino la loro esecuzione
    pthread_join(primo, NULL);
    pthread_join(secondo, NULL);

    return 0;
}