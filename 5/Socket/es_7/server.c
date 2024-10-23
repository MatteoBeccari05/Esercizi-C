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

char* ordina_stringa(const char *str) 
{
    int n = strlen(str);
    char *risultato = malloc(n + 1);
    
    if (risultato == NULL) 
    {
        return NULL; // Controllo per l'allocazione della memoria
    }

    strcpy(risultato, str);  // copia la stringa originale

    //bubble Sort
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (risultato[j] > risultato[j + 1]) 
            {
                // scambia i caratteri
                char temp = risultato[j];
                risultato[j] = risultato[j + 1];
                risultato[j + 1] = temp;
            }
        }
    }

    risultato[n] = '\0';  // aggiungi il terminatore di stringa
    return risultato;      // restituisce la stringa ordinata
}

int main()
{
    struct sockaddr_in servizio, addr_remoto;
    int socketfd, soa, fromlen=sizeof(servizio);
    char stringa_ricevuta[DIM];

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

        char *stringa_ordinata = ordina_stringa(stringa_ricevuta);
        if (stringa_ordinata != NULL) 
        {
            write(soa, stringa_ordinata, strlen(stringa_ordinata));
            free(stringa_ordinata);  // Libera la memoria
        }
        close(soa);
    }
}