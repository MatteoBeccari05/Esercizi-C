#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Numero argomenti sbagliato");
        exit(-1);
    }
	int fd;

	//Creazione FIFO
	if( mkfifo("fifo", 0777) == -1)
	{	
        if(errno!=EEXIST)
		{
			printf("\nErrore nella creazione della fifo\n");
			return 1;
		}		
	}
	//Apro la FIFO in scrittura
	fd=open("fifo", O_WRONLY); 
	printf("Ho aperto la FIFO");

    FILE *origine = fopen(argv[1], "rb");
    if (!origine) 
    {
        printf("Errore apertura file origine");
        exit(-1);
    }

    char buffer[BUFFER_SIZE];
    int n;

    while ((n = fread(buffer, 1, sizeof(buffer), origine)) > 0) 
    {
        if( write(fd, buffer, sizeof(buffer)) == -1) 
	    {
		    printf("\nErrore in scrittura nella FIFO\n");
		    exit(-1);
	    }
    }

	printf("\nHo scritto nella FIFO\n");
    fclose(origine);
	close(fd);

	return 0;
}