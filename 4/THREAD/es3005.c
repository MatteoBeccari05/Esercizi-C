#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <time.h>

/*esercizio 13 pagina 248
In linguaggio c creare 2 thread, il primo genera una sequenza di N numeri casuali, 
con N fornito come argomento della riga di comando, e li inserisce singolarmente in un ring-buffer, 
il secondo preleva i numeri dal ring-buffer condiviso e li visualizza.
la codifica dovrà prevedere la necessaria sincronizzazione fra thread consumatore e thread produttore.*/

#define FETTE 64
#define BUFFER_DIM 1024

typedef struct
{
    unsigned char buffer[BUFFER_DIM];
    int n;
    int contatore; 
} Anello;

Anello buffer[FETTE]; 
int write_index = 0, read_index = 0, fette = 0;
pthread_mutex_t mutex; 
pthread_cond_t not_full, not_empty; 

void *Produttore(void *arg)
{
    int N = *((int *)arg);
    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 100;    
        pthread_mutex_lock(&mutex);
        while (fette == FETTE) 
        {
            pthread_cond_wait(&not_full, &mutex);
        }
        buffer->buffer[write_index] = num;
        write_index = (write_index + 1) % FETTE;
        fette++;
        pthread_cond_signal(&not_empty);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *Consumatore(void *arg)
{
    for (int i = 0; i < *((int *)arg); i++) 
    {
        pthread_mutex_lock(&mutex);
        while (fette == 0) {
            pthread_cond_wait(&not_empty, &mutex);
        }
        int num = buffer->buffer[read_index];
        read_index = (read_index + 1) % FETTE;
        fette--;
        printf("Numero %d: %d\n", i+1, num);
        pthread_cond_signal(&not_full);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Numero argomenti sbagliato");
        exit(-1);
    }

    int N = atoi(argv[1]);
    if (N <= 0) 
    {
        printf("Inserire un numero positivo");
        exit(-1);
    }

    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, NULL, &Produttore, &N);
    pthread_create(&cons_thread, NULL, &Consumatore, &N);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);

    return 0;
}