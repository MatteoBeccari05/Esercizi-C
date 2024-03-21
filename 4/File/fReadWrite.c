
/* Inserendo da terminale un file di origine e un file di 
destinazione il programma copierà il contenuto dal file di origine al file di destinazione.
Se il file di destinazione non esiste il programma lo crea con il nome scritto a terminale dall'utente. */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    FILE *origine , *destinazione;
    int n;
    unsigned char buffer[BUFFER_DIM];

    //controllo che l'utente inserisca i parametri corretti
    if(argc!=3)
    {
        printf("Inserire correttamente i parametri d'ingresso\n");
        exit(1);
    }

    //controllo che l'apertura del file d'orgine sia stata eseguita correttamente
    origine=fopen(argv[1], "r");
    if(origine==NULL)
    {
        printf("Errore apertura file d'origine\n");
        exit(1);
    }

    //controllo che l'apertura del file di destinazione sia stata eseguita correttamente
    destinazione=fopen(argv[2], "w");
    if(destinazione==NULL)
    {
        printf("Errore apertura file di destinazione\n");
        exit(1);
    }

    //copia dei valori
    //legge 1024 byte alla volta, finchè il file termina
    while(!feof(origine))
    {
        n=fread(buffer, 1, BUFFER_DIM, origine);
        if(n>0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
    }

    //chiudo i due file
    fclose(origine);
    fclose(destinazione);
    return 0;
}
