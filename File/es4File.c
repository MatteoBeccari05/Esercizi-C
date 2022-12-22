#include <stdio.h>
#include <string.h>
#define MAX 100

/*creare tre file: F1.txt, F2.txt e risultati.txt*/

void comuni(FILE *f1, FILE *f2, FILE *f3)
{
    char S1[MAX], S2[MAX]; 
    int cont=0;

    f1=fopen("F1.txt", "r");
    f2=fopen("F2.txt", "r");
    f3=fopen("risultati.txt", "w");

    if (f1==NULL || f2==NULL)
    {
        printf("Errore apertura file! \n");
    }

    while (!feof(f1))
    {
        fscanf(f1, "%s", S1);
        rewind(f2);
        while(!feof(f2))
        {
            fscanf(f2,"%s",S2);
            if(strcmp(S1, S2)==0)
            {
                cont++;
            }
        }
    }
    printf("Ci sono %d parole uguali \n", cont);
    fprintf(f3, "Ci sono %d parole uguali", cont);
    fclose(f1); 
    fclose(f2); 
    fclose(f3);
}

int main()
{
    FILE *f1;  
    FILE *f2;  
    FILE *f3;      
    comuni(f1,f2,f3);
    return 0;                     
}