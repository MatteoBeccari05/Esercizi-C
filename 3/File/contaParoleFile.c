#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */
int main()
{ 
    FILE *f1;          
    char P[MAX], S[MAX];    
    int cont=0;
    int parole=0;
    f1=fopen("F1.txt", "r");     
    if (f1==NULL)
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    fscanf(f1, "%s", S);            
    while (!feof(f1))                
    {
        parole++;
        fscanf(f1, "%s", S);
    }
    printf("Ho trovato %d parole \n", parole);
    fclose(f1);                                 
}