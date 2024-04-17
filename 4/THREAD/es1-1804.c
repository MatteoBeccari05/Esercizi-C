#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*Creare un programma che :
1- chiede i dati di uno studente (nome,cognomome, media);
2- crea un thread per stampare a video i dati inseriti;
3- crea un secondo thread per stampare su un file di testo i dati inseriti.*/


typedef struct
{
    char nome[30];
    char cognome[30];
    float media;

} Studente;


void* stampaVideo(void* par)   //la firma è obbligatoriamente così
{
    printf("\n----------------------------------------\n");
    Studente *st1 = (Studente *)par;
    printf("Dati dello studente:\n");
    printf("Nome: %s\n", st1->nome);
    printf("Cognome: %s\n", st1->cognome);
    printf("Media: %.2f\n", st1->media);
    return (void*)0;
}

void* stampaFile(void* par)  
{
    Studente *st1 = (Studente *)par;
    FILE *file = fopen("destinazione.txt", "w");
    if (file == NULL) 
    {
        printf("Errore nell'apertura del file.\n");
        pthread_exit(NULL);
    }
    fprintf(file, "Dati dello studente:\n");
    fprintf(file, "Nome: %s\n", st1->nome);
    fprintf(file, "Cognome: %s\n", st1->cognome);
    fprintf(file, "Media: %.2f\n", st1->media);
    fclose(file);
    return (void*)0;
}

int main()
{
    pthread_t threadScritturaVideo, threadScritturaFile;
    Studente st1;

    //chiedo all'utente i dati 
    printf("Inserire il nome: ");
    scanf("%s", st1.nome);
    printf("Inserire la cognome: ");
    scanf("%s", st1.cognome);
    printf("Inserire la media dello studente: ");
    scanf("%f", &st1.media);

    pthread_create(&threadScritturaVideo, NULL, &stampaVideo, (void*)&st1);   //creo un thread
    pthread_create(&threadScritturaFile, NULL, &stampaFile, (void*) &st1);   //creo un thread

    //Attendo che i 2 thread terminino la loro esecuzione
    pthread_join(threadScritturaFile, NULL);
    pthread_join(threadScritturaVideo, NULL);

    return 0;
}