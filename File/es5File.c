#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
    FILE *f1;
    FILE *f2;
    FILE *f3;
    int lunghezza;
    char stringaMax[MAX];
    char S1[MAX], S2[MAX];
    f1 = fopen("F1.txt", "r");
    f2 = fopen("F2.txt", "r");
    f3 = fopen("risultati.txt", "w");
    if(f1==NULL || f2==NULL)
    {
        printf("Errore apertura file");
    }

    while(!feof(f1))
    {
        fscanf(f1, "%s", S1);
        rewind(f2);
        fscanf(f2, "%s", S2);
        if(strlen(S1)>strlen(S2))
        {
            fprintf(f3, " %s ", S1);
        }
        else if(strlen(S1)<strlen(S2))
        {
            fprintf(f3, " %s ", S2);
        }
    }
       
    fclose(f1);
    fclose(f2);
    fclose(f3);
        
}
    