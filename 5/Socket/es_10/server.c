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

int MAX(int n, int vettore[])
{
    int max = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if (vettore[i] > max) 
        {
            max = vettore[i];
        }
    }
    return max;
}

int MIN(int n, int vettore[])
{
    int min = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        if (vettore[i] < min) 
        {
            min = vettore[i];
        }
    }
    return min;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char invio[DIM];
    int n;
    int max = 0, min = 0;

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

        max = MAX(n, vettore);
        min = MIN(n, vettore);

        sprintf(invio, "Numero MIN: %d - Numero MAX: %d", min, max);

        write(soa, invio, strlen(invio));
        close(soa);
    }
}