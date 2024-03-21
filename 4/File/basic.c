/* il programma in questione apre un file e controlla se è stato aperto correttamente 
successivamente il file viene chiuso e si controlla se è stato chiuso correttamente */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	FILE *fileOrigine;		//dichiaro una variabile di tipo file

	fileOrigine=fopen("nomeFile.txt", "r");   //apro il u nfile in modalità lettura

	if(fileOrigine==NULL)  //controllo se il file è stato aperto correttamente
	{
		printf("Impossibile aprire il file\n");
		exit (1);						//se non lo ho aperto con successo esco dal programma
	}
	else 
	{
		printf("File aperto\n");    
    }

    fclose(fileOrigine);           //chiudo il file
	
    if(fclose(fileOrigine)==0)    //controllo che il file sia stato chiuso con successo
	{
		printf("\nChiusura del file avvenuta con successo\n");
	}	
	else 
	{
		printf("\nChiusura del file fallita\n");
	}

	return 0;
}
