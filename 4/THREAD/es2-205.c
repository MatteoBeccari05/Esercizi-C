#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 1024

//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*-copiare il contenuto di un file di testo in un secondo file (i nomi dei file sono inseriti dall'utente quando avvia il programma);
-le operazioni di lettura e scrittura sono svolte da due thread separati.*/

typedef struct 
{
    FILE *sorgente;
    FILE *destinazione;
} StructFile;

void *Scrittura(void *par) 
{
    StructFile *r1 = (StructFile *)par;
    char buffer[BUFFER_SIZE];
    size_t n;

    // Leggi dal file di origine e scrivi nel file di destinazione
    while ((n = fread(buffer, 1, BUFFER_SIZE, r1->sorgente)) > 0) 
    {
        fwrite(buffer, 1, n, r1->destinazione);
    }

    fclose(r1->sorgente); // Chiudi il file di origine
    fclose(r1->destinazione); // Chiudi il file di destinazione
    return NULL;
}

int main(int argc, char *argv[]) 
{
    pthread_t primo;
    StructFile r1;

    if (argc != 3) 
    {
        printf("Inserire correttamente i parametri d'ingresso\n");
        exit(1);
    }

    // Apertura dei file di origine e di destinazione
    r1.sorgente = fopen(argv[1], "r");
    if (r1.sorgente == NULL) 
    {
        printf("Errore apertura file d'origine\n");
        exit(1);
    }

    r1.destinazione = fopen(argv[2], "w");
    if (r1.destinazione == NULL) 
    {
        printf("Errore apertura file di destinazione\n");
        fclose(r1.sorgente); // Chiudi il file di origine se l'apertura del file di destinazione fallisce
        exit(1);
    }

    // Creazione del thread per la scrittura
    pthread_create(&primo, NULL, &Scrittura, (void *)&r1);

    pthread_join(primo, NULL);

    printf("Copia completata\n");

    return 0;
}

