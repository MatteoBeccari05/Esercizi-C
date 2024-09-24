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
8) Alterni (o scambi) a due a due le posizioni del vettore: esempio
vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
9) Ordini il vettore (ordinamento a scelta).*/

void Stampa(int n1, int vettore[])
{
    printf("Vettore:");
    printf("\n");
    for(int i=0; i<n1 ;i++)
    {
        printf("Posizione %d: %d \n", i,vettore[i]);
    }
}

void StampaMediaSomma(int a, int vettore[])
{
    float somma; 
    float media;
    for(int i=0; i<a; i++)
    {
        somma = somma + vettore[i];
    }

    media = (somma / a);
    printf("La somma dei numeri è: %f", somma);
    printf("\nLa media dei numeri è: %f", media);

}

void StampaNumeriPari(int a, int vettore[])
{
    printf("I numeri pari sono: ");
    printf("\n");
    for(int i=0; i<a; i++)
    {
        if(vettore[i]%2 == 0)
        {
            printf("%d \n",vettore[i]);
        }
    }  
}

void StampaNumeriDispari(int a, int vettore[])
{
    printf("I numeri dispari sono: ");
    printf("\n");
    for(int i=0; i<a; i++)
    {
        if(vettore[i]%2 == 1)
        {
            printf("%d \n",vettore[i]);
        }
    }  
}

void RicercaNumero(int a, int vettore[])
{
    int numero;
    printf("Inserisci il numero da cercare: ");
    scanf("%d",&numero);
    for(int i=0; i<a ;i++)
    {
        if(vettore[i] == numero)
        {
            printf("Numero %d trovato in posizione %d\n", numero, i);
        }
    }
}

void EliminaNumero(int a, int vettore[])
{
    int t,k=0,cont=0;
    int pos,vettore2[100];
    printf("Inserisci il numero da eliminare: ");
    scanf("%d",&t);
    for(int i=0; i<a; i++)
    {
        if(vettore[i] != t)
        {
          vettore2[k] = vettore[i];
          k = k + 1;              
        }
    }   

    for(int i=0; i<k; i++)
    {
        vettore[i] = 0;
        vettore[i] = vettore2[i];
    }
    vettore[a-1] = 0;
}

void ALternaNumeri(int a, int vettore[])
{ 
    int app;   
    for (int i=0; i<a-1; i=i+2)
    {
        app = vettore[i];
        vettore[i] = vettore[i+1];
        vettore[i+1] = app;
    }
    Stampa(a, vettore);
}

void Ordina(int a, int vettore[])  //dal più grande al più piccolo
{ 
    int app;   
    for (int k=0; k<a-1; k++)
    {
        for (int i=k+1; i<a; i++)
        {
            if (vettore[k] < vettore[i])
            {
               app = vettore[k];
               vettore[k] = vettore[i];
               vettore[i] = app;
            }       
        }
    } 
    Stampa(a, vettore);
} 

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
    printf("Inserisci una scelta:");
}

void Lettura(int *n1, int vettore[])
{ 
    do
    {
        printf("Quanti numeri vuoi inserire: ");
        scanf("%d",n1);

    }while(n1 <= 0);

    for(int i=0; i<*n1 ;i++)
    {
        printf("Inserisci il %d numero: ",(i+1));
        scanf("%d",&vettore[i]);
    }
}

void InvertiVettore(int a, int vettore[])
{
    printf("Vettore invertito:");
    printf("\n");
    for(int i = a; i>=0; i--)
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
        scanf("%d", &b);
        switch (b)
	    {
            case 1: 
		    Stampa(a, vettore);
		    break; 
		    case 2: 
	        InvertiVettore(a, vettore);
		    break;
		    case 3: 
	        StampaMediaSomma(a, vettore);
		    break;
		    case 4: 
		    StampaNumeriPari (a, vettore);
		    break;
		    case 5: 
		    StampaNumeriDispari(a, vettore);
		    break;
		    case 6: 
		    RicercaNumero(a, vettore);
		    break;
		    case 7: 
		    EliminaNumero(a, vettore);
		    break;
		    case 8: 
		    ALternaNumeri(a, vettore);
		    break;
		    case 9: 
		    Ordina(a, vettore);
		    break;
	    }

    }while(b<10);

    return 0; 
}