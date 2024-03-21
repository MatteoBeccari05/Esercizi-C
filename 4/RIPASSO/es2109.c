#include <stdio.h>

int main() 
{
    int limite1, limite2;
    int n;
    int somma = 0;

    // Chiedo all'utente di fornire due numeri interi compresi tra 30 e 50
    do
    {
        printf("Inserisci un numero intero tra 30 e 50 per limite1: ");
        scanf("%d", &limite1);

        printf("Inserisci un numero intero tra 30 e 50 per limite2: ");
        scanf("%d", &limite2);

    }while(limite1<30 || limite1>50 || limite2<30 || limite2>50);
    
    printf("Hai inserito i seguenti limiti:\n");
    printf("Limite 1 = %d\n", limite1);
    printf("Limite 2 = %d\n", limite2);

    printf("Inserire 5 numeri interi");
    printf("\nSe saranno compresi tra il limite inferiore = %d e il limite superiore = %d verranno sommati tra loro", limite1, limite2);


    for(int i = 1; i<=5; i++)
    {
        printf("\nInserire il %d^ numero: ", i);
        scanf("%d", &n);
        if(n>=limite1 && n<=limite2)
        {
            somma=somma+n;
        }
    }
    
    // Visualizzo la somma
    printf("\nLa somma dei numeri compresi tra %d e %d = %d\n", limite1, limite2, somma);

    return 0;
}