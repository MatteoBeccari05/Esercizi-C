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
    char str1[DIM],str2[DIM];
    int lunghezza;

    servizio.sin_family = AF_INET;
    servizio.sin_addr.s_addr = htonl(INADDR_ANY);
    servizio.sin_port = htons(SERVERPORT);
    socketID = socket(AF_INET,SOCK_STREAM,0);

    connect(socketID, (struct sockaddr*)&servizio, sizeof(servizio));

    printf("Inserisci la lunghezza del vettore: ");
    scanf("%d", &lunghezza);
    int vettore[lunghezza];

    for(int i = 0; i<lunghezza; i++)
    {
        printf("Inserisci numero: ");
        scanf("%d", &vettore[i]);
    }

    write(socketID, &lunghezza, sizeof(lunghezza));
    write(socketID, vettore, sizeof(vettore));
    

    read(socketID, str2, sizeof(str2));
    printf("\nStringa ricevuta dal server: \n%s", str2);

    close(socketID);
    return 0;
}