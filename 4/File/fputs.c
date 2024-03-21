//CREO UN FILE E CI INSERISCO PARAMETRI DA TASTIERA
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *nomi;  //puntatore ad un oggetto di tipo file
    char vettnomi[20];

    nomi=fopen("nomi.txt", "a"); //apro il file nomi.txt in modalità scrittura (se il file esiste lo apre, se non esiste lo crea)

    if(nomi==NULL)   //se il file non viene aperto
    {
        printf("Errore apertura file!");
        exit(1);
    }

    printf("Ho aperto il file\n");
    
    for(int i = 0; i < 4; i++)
    {
        printf("Inserisci un nome: ");
        scanf("%s", vettnomi);
        fputs(vettnomi, nomi);              //scrive i nomi nel file
        fputc('\n', nomi);                  //manda a capo ogni nome
    }

    fclose(nomi);               //chiudo il file

    return 0;
}