#include<stdio.h>

/*Esercizio 1
Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
2) Visualizzi a video l’array invertito cioè sostituendo il primo elemento con l'ultimo , il secondo con il
penultimo e cosi via;
3) Visualizzi a video la somma e media degli elementi del vettore;
4) Visualizzi a video tutti i numeri pari;
5) Visualizzi a video tutti i numeri dispari;
6) Ricerchi un numero (letto in input) nell’array;
7) Elimini un elemento (letto in input) dell’array (se esistente);
8) Alterni (o scambi ) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).*/

void StampaMenu()
{ 
    printf("\n-----------------------------------\n");
    printf("1) Stampa vettore\n");
    printf("2) Stampa vettore invertito\n");
    printf("3) Stampa somma e media\n");
    printf("4) Stampa numeri pari\n");
    printf("5) Stampa numeri dispari\n");
    printf("6) Cerca un numero nel vettore\n");
    printf("7) Elimina un numero dal vettore\n");
    printf("8) Alterna il vettore \n");
    printf("9) Ordina il vettore\n");
    printf("10) Esci dal programma\n");
    printf("-----------------------------------\n");
    printf("Inserisci una scelta:\n");
}

void Lettura(int *n1, int vettore[])
{ 
    do
    {
        printf("Quanti numeri vuoi inserire: \n");
        scanf("%d",n1);

    }while(n1 <= 0);

    for(int i=0; i<*n1 ;i++)
    {
        printf("Inserisci il %d numero: ",(i+1));
        scanf("%d",&vettore[i]);
    }
}

void Stampa(int n1, int vettore[])
{
    printf("Vettore:");
    printf("\n");
    for(int i=0; i<n1 ;i++)
    {
        printf("Posizione %d: %d \n", i,vettore[i]);
    }
}

void InvertiVettore(int a, int vettore[])
{
    /*int i,k,temp;
    k=n1;
    for (i = 0; i < (n1/2); i++) 
    {
        temp=vett1[i];
        vett1[i]=vett1[k-1];
        vett1[k-1]=temp;
        k--;
    }
    Stampa(n1,vettore);*/

    for(int i = a; i<=0; i--)
    {
        printf("Posizione %d: %d \n", i,vettore[i]);
    }
}  

int main()
{
    int a,b;
    int vettore[100];
    Lettura(&a, vettore);
    printf("\n");
    do
    {
        StampaMenu();
        scanf("%d", &b); //legge la scelta dal menù
        switch (b)
	    {
            case 1: 
		    Stampa(a, vettore);
		    break; 
		    case 2: 
	        InvertiVettore(a, vettore);
		    break;
		    /*case 3: 
	        dispari(a, vett);
		    break;
		    case 4: 
		    inverti (a, vett);
		    break;
		    case 5: 
		    cerca(a, vett);
		    break;
		    case 6: 
		    ordina(a, vett);
		    break;
		    case 7: 
		    elimina1(a, vett);
		    break;
		    case 8: 
		    elimina2(a, vett);
		    break;
		    case 9: 
		    alterna(a, vett);
		    break;*/
	    }

    }while(b<10);

    return 0; 
}