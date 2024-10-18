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

void invertiStringa(char str[], char str_contrario[]) 
{
    int lunghezza = strlen(str);
    for (int i = 0; i < lunghezza; i++) 
    {
        str_contrario[i] = str[lunghezza - i - 1];
    }
    str_contrario[lunghezza] = '\0'; // Aggiunge il terminatore di stringa
}

int Palindroma(char stringa[]) 
{
    int palindroma = 0;
    char str_contrario[DIM];
    invertiStringa(stringa, str_contrario);
    
    if(strcmp(stringa, str_contrario) == 0)
    {
        palindroma = 1;
    }
    else
    {
        palindroma = 0;
    }
    return palindroma;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char stringa_ricevuta[DIM], invio[DIM];

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
        if(Palindroma(stringa_ricevuta) == 1)
        {
            strcpy(invio, "La stringa è palindroma");
        }
        else
        {
            strcpy(invio, "La stringa non è palindroma");
        }

        write(soa, invio, strlen(invio));
        close(soa);
    }
}