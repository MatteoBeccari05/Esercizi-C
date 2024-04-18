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

//il programma esegue la ricerca con due thread ma con un solo metodo

typedef struct
{
    int numeroDaCercare;
    int array[10];
    int inizio;
    int fine;
} Ricerca;

void* PrimaMeta(void* par)   //la firma è obbligatoriamente così
{
    Ricerca r1 = *(Ricerca *)par;
    for(int i = r1.inizio; i<r1.fine; i++)
    {
        if(r1.array[i] == r1.numeroDaCercare)
        {
            printf("Il numero %d è stato trovato in posizione %d\n", r1.numeroDaCercare, i+1);
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


    r1.inizio = 0;
    r1.fine = SIZE/2;
    pthread_create(&primo, NULL, &PrimaMeta, (void*)&r1);   //creo un thread
    pthread_join(primo, NULL);

    r1.inizio = SIZE/2;
    r1.fine = SIZE;
    pthread_create(&secondo, NULL, &PrimaMeta, (void*) &r1);   //creo un thread
    pthread_join(secondo, NULL);

    return 0;
}