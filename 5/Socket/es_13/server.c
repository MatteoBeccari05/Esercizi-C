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
#include <limits.h>

#define DIM 512
#define SERVERPORT 1313

int Pari(int a, int vettore[])
{
    int contatore = 0;
    for(int i=0; i<a; i++)
    {
        if(vettore[i]%2 == 0)
        {
            contatore++;
        }
    }  
    return contatore;
}

int Dispari(int a, int vettore[])
{
    int contatore = 0;
    for(int i=0; i<a; i++)
    {
        if(vettore[i]%2 == 1)
        {
            contatore++;
        }
    } 
    return contatore; 
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char invio[DIM];
    int n;
    int pari, dispari;

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
        read(soa, vettore, n * sizeof(int));

        pari = Pari(n, vettore);
        dispari = Dispari(n, vettore);

        sprintf(invio, "I numeri pari sono: %d - I numeri dispari sono: %d", pari, dispari);

        write(soa, invio, sizeof(invio));
        close(soa);
    }
}