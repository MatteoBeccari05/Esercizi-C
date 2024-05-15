#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

#define N 16
#define BUFFER_DIM 64

//gcc lezione1104.c -o saluti -lpthread => per compilare il programma
//thread POSIX (in linux è lo standard)

/*Realizzare la seconda versione del programma "copia e incolla di un file con i thread" 
utilizzando (oltre al ring buffer) anche il mutex e le API POSIX wait e signal.  
La soluzione è riportata nell'esempio di pag. 236-237-238 (non limitarsi a copiare la soluzione: 
analizzarla ed elaborarla dopo aver cercato una soluzione in autonomia). 
Per completare l'argomento studiare anche le pagine 234 e 235.*/

typedef struct 
{
    unsigned char buffer[BUFFER_DIM];
    int n;
} BUFFER;

BUFFER bufferRing[N];
int readIndex = 0;
int writeIndex = 0;
int block = 0;
int eof = 0;
pthread_mutex_t critico, mutex;
pthread_cond_t notFull, notEmpty; 
FILE *dest, *or;

void *Lettura(void* par) 
{
    int n;
    while(!feof(or))
    {
        pthread_mutex_lock(&critico);
        
        if(block >= N)
        {
            pthread_cond_wait(&notFull, &critico);
        }

        n = fread(bufferRing[writeIndex].buffer, 1, BUFFER_DIM, or);

        if(n>0)
        {
            bufferRing[writeIndex].n = n;
            writeIndex = (writeIndex + 1) % N;
            pthread_mutex_lock(&mutex);
            block++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&notEmpty);
        }
        pthread_mutex_unlock(&critico);
    }
    eof = 1;
    pthread_cond_signal(&notEmpty);
    pthread_exit(NULL);
}

void *Scrittura(void* par) 
{
    while (1)
    {
        if(eof && block == 0)
        {
            break;
        }
        pthread_mutex_lock(&critico);

        if(block>0)
        {
            fwrite(bufferRing[readIndex].buffer, 1, bufferRing[readIndex].n, dest);
            readIndex = (readIndex + 1) % N;
            pthread_mutex_lock(&mutex);
            block--;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&notFull);
        }
        else
        {
            //in caso di buffer vuoto
            pthread_cond_wait(&notEmpty, &critico);
        }
        pthread_mutex_unlock(&critico);
    }
    pthread_exit(NULL);
}


int main(int argc, char *argv[]) 
{
    pthread_t lettura, scrittura;

    if (argc != 3) 
    {
        printf("Inserire correttamente i parametri d'ingresso\n");
        exit(1);
    }

    // Apertura dei file di origine e di destinazione
    or = fopen(argv[1], "rb");
    if (or == NULL) 
    {
        printf("Errore apertura file d'origine\n");
        exit(1);
    }

    dest = fopen(argv[2], "wb");
    if (dest == NULL) 
    {
        printf("Errore apertura file di destinazione\n");
        fclose(or);
        exit(1);
    }

    pthread_mutex_init(&critico, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&notEmpty, NULL);
    pthread_cond_init(&notFull, NULL);

    pthread_create(&lettura, NULL, &Lettura, NULL);
    pthread_create(&scrittura, NULL, &Scrittura, NULL);

    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);

    pthread_mutex_destroy(&critico);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&notEmpty);
    pthread_cond_destroy(&notFull);

    fclose(dest); 
    fclose(or);

    printf("\nCopia completata\n");

    return 0;
}