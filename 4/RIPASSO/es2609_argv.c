#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    //Assegnazione variabili
    int limite1 = atoi(argv[1]);
    int limite2 = atoi(argv[2]);
    int n[5];
    int somma = 0;

    if(limite1>=30 && limite1<=50 && limite2>=30 && limite2<=50)
    {
        printf("Hai inserito i seguenti limiti:\n");
        printf("Limite 1 = %d\n", limite1);
        printf("Limite 2 = %d\n", limite2);

        printf("Inserire 5 numeri interi");
        printf("\nSe saranno compresi tra il limite inferiore = %d e il limite superiore = %d verranno sommati tra loro", limite1, limite2);

        //Inserire i numeri nel vettore
        for(int i = 1; i<=5; i++)
        {
            printf("\nInserire il %d^ numero: ", i);
            scanf("%d", &n[i]);
            if(n[i]>=limite1 && n[i]<=limite2)
            {
                somma=somma+n[i];
            }
        }
    
        // Visualizzo la somma
        printf("\nLa somma dei numeri compresi tra %d e %d = %d\n", limite1, limite2, somma);

        //Visualizzo i vari numeri nella posizione del vettore
        printf("\nNumeri inseriti nel vettore: \n");
        for(int i=1; i<=5;i++)
        {
            printf("Numero in posizione %d: %d\n", i-1, n[i]);
        }
    }
    else
    {
        printf("Limiti inseriti non validi");
        exit(0);
    }
    
    return 0;
}