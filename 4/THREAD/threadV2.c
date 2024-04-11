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

void* stampaGiorno(void* par)   //la firma è obbligatoriamente così
{
    printf("%s\n", (char*)par);
    return (void*)0;
}

void* stampaSera(void* par)  
{
    printf("%s\n", (char*)par);
    return (void*)0;
}

void* stampaNotte(void* par)  
{
    printf("%s\n", (char*)par);
    return (void*)0;
}

int main()
{
    pthread_t threadGiorno, threadSera, threadNotte;
    char* msg1 = "Buongiorno";
    char* msg2 = "Buonasera";
    char* msg3 = "Buonanotte";

    printf("Ciao\n");  //lo faccio fare al thread principale

    pthread_create(&threadGiorno, NULL, &stampaGiorno, msg1);   //creo un thread
    pthread_create(&threadSera, NULL, &stampaSera, msg2);   //creo un thread
    pthread_create(&threadNotte, NULL, &stampaNotte, msg3);  //creo un thread

    //Attendo che i 3 thread terminino la loro esecuzione
    pthread_join(threadGiorno, NULL);
    pthread_join(threadSera, NULL);
    pthread_join(threadNotte, NULL);
    


    //printf("Buongiorno\n");
    //printf("Buonasera\n");
    //printf("Buonanotte\n");

    return 0;
}