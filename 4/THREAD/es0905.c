#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 64
#define BUFFER_DIM 1024

//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*-copiare il contenuto di un file di testo in un secondo file (i nomi dei file sono inseriti dall'utente quando avvia il programma);
-le operazioni di lettura e scrittura sono svolte da due thread separati.*/

typedef struct 
{
    unsigned char buffer[BUFFER_DIM];
    int n;
} BUFFER;

BUFFER f1[BUFFER_SIZE];
int readIndex = 0;
int writeIndex = 0;
int block = 0;
int eof = 0;

void *Lettura(void* par) 
{
    FILE *file = (FILE *)par;
    while(!feof(file))
    {
        while(block >= BUFFER_SIZE);
        int n = fread(f1[writeIndex].buffer, 1, BUFFER_DIM, file);
        if(n>0)
        {
            f1[writeIndex].n = n;
            writeIndex = (writeIndex + 1) % BUFFER_SIZE;
            block++;
        }
    }
    eof = 1;
}

void *Scrittura(void* par) 
{
    FILE *file = (FILE *)par;
    while (eof == 0 || block > 0)
    {
        if(block>0)
        {
            fwrite(f1[readIndex].buffer, 1, f1[readIndex].n, file);
            readIndex = (readIndex + 1) % BUFFER_SIZE;
            block--;
        }
    }
}


int main(int argc, char *argv[]) 
{
    pthread_t lettura, scrittura;
    FILE *dest, *origine;

    if (argc != 3) 
    {
        printf("Inserire correttamente i parametri d'ingresso\n");
        exit(1);
    }

    // Apertura dei file di origine e di destinazione
    origine = fopen(argv[1], "rb");
    if (origine == NULL) 
    {
        printf("Errore apertura file d'origine\n");
        exit(1);
    }

    dest = fopen(argv[2], "wb");
    if (dest == NULL) 
    {
        printf("Errore apertura file di destinazione\n");
        fclose(dest); // Chiudi il file di origine se l'apertura del file di destinazione fallisce
        fclose(origine);
        exit(1);
    }

    // Creazione del thread per la scrittura
    pthread_create(&lettura, NULL, &Lettura, (void*)origine);
    pthread_create(&scrittura, NULL, &Scrittura, (void*)dest);

    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);

    fclose(dest); // Chiudi il file di origine se l'apertura del file di destinazione fallisce
    fclose(origine);

    printf("\nCopia completata\n");

    return 0;
}
