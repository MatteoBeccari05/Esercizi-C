//CLIENT
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

#define DIM 512
#define SERVERPORT 1313

int main()
{
    struct sockaddr_in servizio;
    int socketID;
    char str1[DIM], carattere[1], stringa_ricevuta[DIM];

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketID = socket(AF_INET,SOCK_STREAM,0);

    connect(socketID, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("Inserisci la stringa: ");
    scanf("%s",str1);
    write(socketID, str1, strlen(str1) + 1);

    printf("\nInserisci il carattere da ricercare: ");
    scanf("%s",carattere);
    write(socketID, carattere, sizeof(carattere));

    read(socketID, stringa_ricevuta, sizeof(stringa_ricevuta));
    printf("\nStringa ricevuta dal server: \n%s\n", stringa_ricevuta);

    close(socketID);
    return 0;
}