//STAMPA IL CONTENUTO DI UN FILE
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *nomi;  //puntatore ad un oggetto di tipo file
    char c;

    nomi=fopen("nomi.txt", "r"); //apro il file nomi.txt in modalità lettura 

    if(nomi==NULL)   //se il file non viene aperto
    {
        printf("Errore apertura file!");
        exit(1);
    }

    do
    {
        c=fgetc(nomi);      //leggo un carattere all'interno del file e lo stampo a video
        putchar(c);

    } while (c != EOF);   //eof: end of file
    
    
    

    fclose(nomi);               //chiudo il file

    return 0;
}