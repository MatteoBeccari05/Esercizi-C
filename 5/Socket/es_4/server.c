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

int ContaVocali(char stringa[])
{
    int vocali = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        char c = tolower(stringa[i]); // Per gestire le maiuscole
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vocali++;
        }
    }
    return vocali;
}

int ContaConsonanti(char stringa[])
{
    int consonanti = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        char c = tolower(stringa[i]); // Per gestire le maiuscole
        if ((c >= 'a' && c <= 'z') && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'))
        {
            consonanti++;
        }
    }
    return consonanti;
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char stringa_ricevuta[DIM], stringaNuova[DIM];
    int vocali, consonanti;

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
        vocali = ContaVocali(stringa_ricevuta);
        consonanti = ContaConsonanti(stringa_ricevuta);

        sprintf(stringaNuova, "Consonanti: %d\nVocali: %d\n", consonanti, vocali);

        write(soa, stringaNuova, strlen(stringaNuova));
        close(soa);
    }
}