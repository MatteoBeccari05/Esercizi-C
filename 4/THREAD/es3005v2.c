#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define FETTE 64

/*esercizio 13 pagina 248
In linguaggio c creare 2 thread, il primo genera una sequenza di N numeri casuali, 
con N fornito come argomento della riga di comando, e li inserisce singolarmente in un ring-buffer, 
il secondo preleva i numeri dal ring-buffer condiviso e li visualizza.
la codifica dovrà prevedere la necessaria sincronizzazione fra thread consumatore e thread produttore.*/

//inserire un numero casuale ogni due secondi

typedef struct {
    int buffer[FETTE];
    int write_index;
    int read_index;
    int n;
    pthread_mutex_t mutex;
    pthread_cond_t not_full;
    pthread_cond_t not_empty;

} Anello;

Anello buffer = {
    .write_index = 0,
    .read_index = 0,
    .n = 0,
};

void *Produttore(void *arg) 
{
    int N = *((int *)arg);

    for (int i = 0; i < N; i++) 
    {
        int num = rand() % 100;  // Genera un numero casuale tra 0 e 99
        pthread_mutex_lock(&buffer.mutex);
        while (buffer.n == FETTE) 
        {
            pthread_cond_wait(&buffer.not_full, &buffer.mutex);
        }
        buffer.buffer[buffer.write_index] = num;
        buffer.write_index = (buffer.write_index + 1) % FETTE;
        buffer.n++;
        pthread_cond_signal(&buffer.not_empty);
        pthread_mutex_unlock(&buffer.mutex);
        sleep(2);  // Aspetta per due secondi
    }
    return NULL;
}

void *Consumatore(void *arg) 
{
    int N = *((int *)arg);

    for (int i = 0; i < N; i++) 
    {
        pthread_mutex_lock(&buffer.mutex);
        while (buffer.n == 0) 
        {
            pthread_cond_wait(&buffer.not_empty, &buffer.mutex);
        }
        int num = buffer.buffer[buffer.read_index];
        buffer.read_index = (buffer.read_index + 1) % FETTE;
        buffer.n--;
        printf("Numero %d: %d\n", i + 1, num);
        pthread_cond_signal(&buffer.not_full);
        pthread_mutex_unlock(&buffer.mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Numero argomenti sbagliato\n");
        return -1;
    }

    int numeri = atoi(argv[1]);

    if (numeri <= 0) 
    {
        printf("Inserire un numero positivo\n");
        return -1;
    }

    srand(time(NULL));  // Inizializza il generatore di numeri casuali

    pthread_t produttore, consumatore;

    pthread_create(&produttore, NULL, Produttore, &numeri);
    pthread_create(&consumatore, NULL, Consumatore, &numeri);

    pthread_join(produttore, NULL);
    pthread_join(consumatore, NULL);

    pthread_mutex_destroy(&buffer.mutex);
    pthread_cond_destroy(&buffer.not_empty);
    pthread_cond_destroy(&buffer.not_full);

    return 0;
}