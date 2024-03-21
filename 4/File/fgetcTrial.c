/* Il programma in questione stampa a video il contenuto del file nomi.txt */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fileOrigine;     //dichiaro una variabile di tipo file
	char c;
	fileOrigine=fopen("nomi.txt", "r");  //apro il file nomi.txt in modalità lettura
	if(fileOrigine==NULL) 	//controllo se il file è stato aperto correttamente
	{
		printf("Impossibile aprire il file\n");
		exit (1);									//se non lo ho aperto con successo esco dal programma
	}
	else 
	{
		c=fgetc(fileOrigine);  //leggo un carattere all'interno del file e lo stampo a video
		while (c!=EOF)
		{
			putchar(c);    //stampa ogni carattere fino alla fine del file (EOF)
			c=fgetc(fileOrigine);		
	    }
	
		if(fclose(fileOrigine)==0) 	//chiudo il file e controllo che sia stato chiuso correttamente
		{
			printf("\n\nChiusura del file avvenuta con successo\n");
		}
		else 
		{
			printf("\n\nChiusura del file fallita\n");
		}
    }
    return 0;
}
