//SERVER
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int Somma_Dispari(int a, int vettore[])
{
    float somma_dispari = 0; 
    for(int i=0; i<a; i++)
    {
        if(vettore[i] %2 != 0)
        {
            somma_dispari = somma_dispari + vettore[i];
        }
    }

    return somma_dispari;
}

int Media_Dispari(int a, int vettore[])
{
    float media_dispari = 0;
    int contatore = 0;
    for(int i=0; i<a; i++)
    {
        if(vettore[i] %2 != 0)
        {
            contatore++;
        }
    }
    media_dispari = (Somma_Dispari(a, vettore) / contatore);
}

int Somma_Pari(int a, int vettore[])
{
    float somma_pari = 0; 
    for(int i=0; i<a; i++)
    {
        if(vettore[i] %2 == 0)
        {
            somma_pari = somma_pari + vettore[i];
        }
        
    }
    return somma_pari;
}

int Media_Pari(int a, int vettore[])
{
    float media_pari = 0;
    int contatore = 0;
    for(int i=0; i<a; i++)
    {
        if(vettore[i] %2 == 0)
        {
            contatore++;
        }
    }
    media_pari = (Somma_Pari(a, vettore) / contatore);
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char invio[DIM];
    int n;
    float somma_dispari = 0, media_dispari = 0;
    float somma_pari = 0, media_pari = 0;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketfd = socket(AF_INET,SOCK_STREAM,0);

    bind(socketfd, (struct sockaddr*)&servizio, sizeof(servizio));

    listen(socketfd, 10);// può attendere fino a 10 client

    while(1)
    {
        printf("\n\nServer in ascolto...");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr*)&addr_remoto, &fromlen);
        //legge dal client
        read(soa, &n, sizeof(n));
        int vettore[n];
        read(soa, vettore, sizeof(vettore));
        

        media_dispari = Media_Dispari(n, vettore);
        somma_dispari = Somma_Dispari(n, vettore);
        media_pari = Media_Pari(n, vettore);
        somma_pari = Somma_Pari(n, vettore);

        sprintf(invio, "La media dispari è: %.1f - La somma dispari è: %.1f \nLa media pari è: %.1f - La somma pari è: %.1f", media_dispari, somma_dispari, media_pari, somma_pari);

        write(soa, invio, strlen(invio));
        close(soa);
    }
}