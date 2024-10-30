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

int VerificaStringa(char stringa1[], char stringa2[])
{
    int ritorno;
    if(strcmp(stringa1, stringa2) == 0)
    {
        ritorno = 0;
    }
    else if(strlen(stringa1) > strlen(stringa2))
    {
        ritorno = 1;
    }
    else if(strlen(stringa1) < strlen(stringa2))
    {
        ritorno = 2;
    }
    return ritorno;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char invio[DIM];
    int n;
    char str1[DIM], str2[DIM];

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
        read(soa, str1, sizeof(str1));
        read(soa, str2, sizeof(str2));

        if(VerificaStringa(str1, str2) == 0)
        {
            strcpy(invio, "Le due stringhe sono uguali");
        }
        else if(VerificaStringa(str1, str2) == 1)
        {
            strcpy(invio, "La prima stringa è la piu lunga");
        }
        else if(VerificaStringa(str1, str2) == 2)
        {
            strcpy(invio, "La seconda stringa è la piu lunga");
        }


        write(soa, invio, sizeof(invio));
        close(soa);
    }
}