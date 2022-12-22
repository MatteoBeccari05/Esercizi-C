#include <stdio.h>
#include <string.h>
#define MAX 100

void ContaParole(FILE *f1, char S[MAX])
{
    char P[MAX];   
    int cont=0;
    int parole=0;
    f1=fopen("F1.txt", "r");     
    if (f1==NULL)
    {
        printf("Errore apertura del file!\n");
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
void ContaVocali(FILE *f1, char S[MAX])
{
    int contaVocali=0;
    int contaConsonanti=0;
    f1=fopen("F1.txt", "r");
    if (f1==NULL)
    {
        printf("Errore apertura del file!\n");
        return;
    }
    while (!feof(f1))
    {
        fscanf(f1, "%s", S);
        for (int i=0;i<strlen(S);i++)
        {
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u')
            {
                contaVocali++;
            }
            else if((S[i] != 'a' || S[i] != 'e' || S[i] != 'i' || S[i] != 'o' || S[i] != 'u')&&(S[i]>97 && S[i]<122))
            {
                contaConsonanti++;
            }
        }
        
    }
    printf("Le vocali del file sono: %d \n", contaVocali);
    printf("Le consonanti del file sono: %d \n", contaConsonanti);
    fclose(f1);
    
}

int main()
{
    char S[MAX];
    FILE *f1;
    ContaParole(f1, S);
    ContaVocali(f1, S);
}