#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */
int main()
{ 
    FILE *f1;          //dichiarazione di file
    char P[MAX], S[MAX];    //dichiarazione di due stringhe con lunghezza massima 81
    int cont=0;
    f1=fopen("F1.txt", "r");     //apro il file e lo vado a leggere  "r"=lettura
    if (f1==NULL)
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    printf("\nInserire una parola da cercare: ");
    scanf("%s", P);
    fscanf(f1, "%s", S);             //legge una stringa alla volta e salva quello che ha letto in S
    while (!feof(f1))                //legge finchè non finisce il file
    {
        if (strcmp(S,P)==0)            //confronto 
        {
            printf("\nHo trovato %s!\n", P);    
            cont++;
        }
        fscanf(f1, "%s", S);
    }
    printf("Trovata la parola %s %d volte \n", P, cont);
    fclose(f1);                                 //chiudo il file
}