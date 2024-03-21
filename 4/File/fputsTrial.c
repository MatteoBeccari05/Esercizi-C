
/*Nel programma in questione vengono chiesti in input 4 nomi, inseriti in un array ed inseriti in 
un file. A questo punto il file viene chiuso e riaperto in modalità lettura e gli elementi all'interno del file vengono stampati a schermo*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 20 
#define qtaNomi 4 
int i;

int main()
{
	FILE *fileDestinazione;		//puntatore ad un oggetto di tipo file
	char vett[MAX_STR]; 		//dichiarazione vettore di char 
	
	fileDestinazione=fopen("nomi.txt", "w");   //apro o creo il file nomi.txt
	if(fileDestinazione==NULL)  	//controllo se il file è stato aperto correttamente
	{
		printf("Impossibile aprire il file\n");
		exit (1);			//se il file non viene aperto chiudo il programma
	}
	else 
	{
		for(i=0; i<qtaNomi; i++)  //tramite il for inserisco 4  nomi nell'array
		{
			printf("Inserisci il %d^ nome: ", i+1);
			scanf("%s", vett);       
			
			fputs(vett, fileDestinazione);  //copio il contenuto dell'array nel file 
			
			fputc('\n', fileDestinazione); 		//ad ogni nome vado a capo
			
		}	 
    }
    fclose(fileDestinazione);		//chiusura del file
    
    fileDestinazione=fopen("nomi.txt", "r");    //riapro il file in modalità lettura
	
	while( fgets(vett, MAX_STR, fileDestinazione) ) 	//stampo tutti gli elementi all'interno del file
	{
		printf("%s", vett); 
	}
		
    
    if(fclose(fileDestinazione)==0) 		//chiudo il file e verifico che la chiusura avvenga correttamente
	{
		printf("\n\nChiusura del file avvenuta con successo\n");	
	}
	else 
	{
		printf("\n\nChiusura del file fallita\n");
	}

	return 0;
}
