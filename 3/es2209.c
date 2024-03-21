#include <stdio.h>

int main() 
{
    //Assegnazione variabili
    int limite1, limite2;
    int n[5];
    int somma = 0;

    // Chiedo all'utente di fornire due numeri interi compresi tra 30 e 50
    //Tramite il ciclo do-while chiedo di inserire i limiti finchè entrambi rispettino le condizioni
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
        printf("Numero in posizione %d: %d\n", i, n[i]);
    }

    return 0;
}