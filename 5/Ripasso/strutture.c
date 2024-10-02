#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 2
/*Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto con i seguenti
campi: ModelloAuto, marca, cilindrata, prezzo, anno_immatricolazione, determinare:
1) Il prezzo + alto e quello + basso visualizzando anche il modello dell&#39;auto;
2) Ordinare la lista delle auto in base all&#39;anno d&#39;immatricolazione;
3) Visualizzare il nome delle auto a partire da un prezzo scelto dall&#39;utente.*/

typedef struct Auto
{
    char modello[20];
    char marca[20];
    int cilindrata;
    int anno_immatricolazione;
    int prezzo;
} Auto;

void Inserimento(Auto automobili[])
{
    for (int i = 0; i < DIM; i++)
    {
        printf("Inserire il modello dell'auto: ");
        scanf("%s", automobili[i].modello);

        printf("Inserire la marca dell'auto: ");
        scanf("%s", automobili[i].marca);

        printf("Inserire la cilindrata dell'auto: ");
        scanf("%d", &automobili[i].cilindrata);

        printf("Inserire l'anno di immatricolazione dell'auto: ");
        scanf("%d", &automobili[i].anno_immatricolazione);

        printf("Inserire il prezzo dell'auto: ");
        scanf("%d", &automobili[i].prezzo);

        printf("\n");
    }
}

void Visualizza(Auto automobili[])
{
    for(int i = 0; i<DIM; i++)
    {
        printf("\nAuto %d\n", i+1);
        printf("Modello: %s\n", automobili[i].modello);
        printf("Marca: %s\n", automobili[i].marca);
        printf("Cilindrata: %d\n", automobili[i].cilindrata);
        printf("Anno immatricolazione: %d\n", automobili[i].anno_immatricolazione);
        printf("Prezzo: %d\n", automobili[i].prezzo);
        printf("\n");
    }
}

void PrezzoPiuAlto(Auto automobili[])
{
    int prezzoMax = automobili[0].prezzo;
    int indiceMax = 0;

    for (int i = 1; i < DIM; i++) {
        if (automobili[i].prezzo > prezzoMax) {
            prezzoMax = automobili[i].prezzo;
            indiceMax = i;
        }
    }

    printf("\nAuto con il prezzo più alto\n");
    printf("Modello: %s\n", automobili[indiceMax].modello);
    printf("Marca: %s\n", automobili[indiceMax].marca);
    printf("Cilindrata: %d\n", automobili[indiceMax].cilindrata);
    printf("Anno immatricolazione: %d\n", automobili[indiceMax].anno_immatricolazione);
    printf("Prezzo: %d\n", automobili[indiceMax].prezzo);
    printf("\n");
}

void PrezzoPiuBasso(Auto automobili[])
{
    int prezzoMin = automobili[0].prezzo;
    int indiceMin = 0;

    for (int i = 1; i < DIM; i++) {
        if (automobili[i].prezzo < prezzoMin) {
            prezzoMin = automobili[i].prezzo;
            indiceMin = i;
        }
    }

    printf("\nAuto con il prezzo più basso\n");
    printf("Modello: %s\n", automobili[indiceMin].modello);
    printf("Marca: %s\n", automobili[indiceMin].marca);
    printf("Cilindrata: %d\n", automobili[indiceMin].cilindrata);
    printf("Anno immatricolazione: %d\n", automobili[indiceMin].anno_immatricolazione);
    printf("Prezzo: %d\n", automobili[indiceMin].prezzo);
    printf("\n");
}
    
void VisualizzaAutoPerPrezzo(Auto automobili[], int prezzoScelto)
{
    printf("Auto con prezzo superiore a %d:\n", prezzoScelto);

    for (int i = 0; i < DIM; i++) 
    {
        if (automobili[i].prezzo > prezzoScelto)
        {
            printf("\nAuto %d\n", i+1);
            printf("Modello: %s\n", automobili[i].modello);
            printf("Marca: %s\n", automobili[i].marca);
            printf("Cilindrata: %d\n", automobili[i].cilindrata);
            printf("Anno immatricolazione: %d\n", automobili[i].anno_immatricolazione);
            printf("Prezzo: %d\n", automobili[i].prezzo);
            printf("\n");
        }
    }
}

void OrdinamentoAuto(Auto automobili[])
{
    Auto temp;
    for (int i = 0; i < DIM - 1; i++) 
    {
        for (int j = i + 1; j < DIM; j++) 
        {
            if (automobili[i].anno_immatricolazione > automobili[j].anno_immatricolazione) 
            {
                temp = automobili[i];
                automobili[i] = automobili[j];
                automobili[j] = temp;
            }
        }
    }
    Visualizza(automobili);
}

int Menu()
{
    int scelta;
    printf("\n============================================================");
    printf("\n1)  Inserisci  3 auto");
    printf("\n2)  Visualizza le auto");
    printf("\n3)  Visualizza l'auto con prezzo piu alto");
    printf("\n4)  Visualizza l'auto con il prezzo più basso");
    printf("\n5)  Visualizza le auto in base all'anno di immatricolazione");
    printf("\n6)  Visualizza le auto secondo un prezzo");
    printf("\n7)  Esci dal programma");
    printf("\n============================================================\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int main()
{
    Auto automobili[DIM];
    int scelta;
    int prezzoScelto;
    do
    {
        scelta = Menu();
        switch (scelta)
        {
            case 1: Inserimento(automobili); break;
            case 2: Visualizza(automobili); break;
            case 3: PrezzoPiuAlto(automobili); break;
            case 4: PrezzoPiuBasso(automobili); break;
            case 5: OrdinamentoAuto(automobili); break;

            case 6: 
            {
                printf("\nInserisci un prezzo per visualizzare le auto sopra tale prezzo: ");
                scanf("%d", &prezzoScelto);
                VisualizzaAutoPerPrezzo(automobili, prezzoScelto);
                break;
            }
        
        }

    } while (scelta<7);
    
    return 0;
}