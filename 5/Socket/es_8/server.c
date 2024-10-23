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

int StampaMedia(int a, int vettore[])
{
    float somma = 0; 
    float media = 0;
    for(int i=0; i<a; i++)
    {
        somma = somma + vettore[i];
    }

    media = (somma / a);
    return media;

}

int StampaSomma(int a, int vettore[])
{
    float somma = 0; 
    for(int i=0; i<a; i++)
    {
        somma = somma + vettore[i];
    }
    return somma;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char invio[DIM];
    int n;
    float somma=0, media=0;

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
        

        media = StampaMedia(n, vettore);
        somma = StampaSomma(n, vettore);

        sprintf(invio, "La media è: %.1f - La somma è: %.1f", media, somma);

        write(soa, invio, strlen(invio));
        close(soa);
    }
}