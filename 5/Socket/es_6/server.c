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

int ContaLettere(char stringa[], char carattere[1])
{
    int frequenza = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == carattere[0])
        {
            frequenza++;
        }
    }
    return frequenza;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char stringa_ricevuta[DIM], invio[DIM], carattere[1];
    int numero_caratteri;

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
        read(soa, stringa_ricevuta, sizeof(stringa_ricevuta));
        read(soa, carattere, sizeof(carattere));

        numero_caratteri = ContaLettere(stringa_ricevuta, carattere);

        sprintf(invio, "Sono stati trovati %d caratteri", numero_caratteri);

        write(soa, invio, strlen(invio));
        close(soa);
    }
}