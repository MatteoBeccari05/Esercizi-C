#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define DIM1 20
#define DIM2 10

/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Che contenga solo lettere;
2) Il conteggio di una lettera (se presente) scelta dall’utente;
3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
dispari;
4) Verifichi se contiene doppie.
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quali sono le lettere contenute in ambedue le stringhe;
3) Quale delle 2 stringhe contiene più vocali;
4) Quale delle 2 stringhe contiene più consonanti;*/

int Menu()
{
    int scelta;
    printf("\n============================================================");
    printf("\n1)  Verifica se la stringa contiene solo lettere");
    printf("\n2)  Verificare la frequenza di una lettera");
    printf("\n3)  Crea due stringhe: Pari e Dispari");
    printf("\n4)  Verifica le doppie nella stringa");
    printf("\n5)  Inserire un'altra stringa");
    printf("\n6)  Stringa più lunga");
    printf("\n7)  Cerca lettere contenute nelle due stringhe");
    printf("\n8)  Quale stringa contiene più vocali");
    printf("\n9)  Quale stringa contiene più consonanti");
    printf("\n10) Esci dal programma");
    printf("\n============================================================\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}


int VerificaLettera(char stringa[])
{
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] < 97 || stringa[i] > 122)
        {
            return 0;
        }
    }
    return 1;
}

int ContaLettere(char stringa[], char carattere)
{
    int frequenza = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == carattere)
        {
            frequenza++;
        }
    }
    return frequenza;
}

void StringaPariDispari(char stringa[], char stringa_pari[], char stringa_dispari[])
{
    int k = 0, t = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (i % 2 == 0) //lettere pari
        {
            stringa_pari[k] = stringa[i];
            k++;
        }
        else //lettere dispari
        {
            stringa_dispari[t] = stringa[i];
            t++;
        }
    }
}

int ContaDoppioni(char stringa[])
{
    int doppioni = 0;
    for (int i = 1; i < strlen(stringa); i++)
    {
        if (stringa[i - 1] == stringa[i])
        {
            doppioni++;
        }
    }
    return doppioni;
}


int main(int argc, char *argv[])
{
    char stringa[DIM1], dispari[DIM1], pari[DIM1];
    int scelta, frequenza, doppioni;
    char lettereDaCercare;

    printf("Inserisci una stringa: ");
    fgets(stringa, DIM1, stdin);
    for (int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = tolower(stringa[i]);
    }

    do
    {
        scelta = Menu();
        switch (scelta)
	    {
            case 1: 
            {
                if(VerificaLettera(stringa) == 1)
                {
                    printf("La stringa contiene solo lettere\n");
                }
                else
                {
                    printf("La stringa non contiene solo lettere\n");
                }
                break; 
            }
		    
		    case 2: 
            {
                printf("Conta frequenza di una lettera: ");
                printf("Inserisci lettera: ");
                scanf("\n%c", &lettereDaCercare);
                frequenza = ContaLettere(stringa, lettereDaCercare);
                printf("\nLa frequenza della lettera %c è di %d\n", lettereDaCercare, frequenza);
                break;
            }
	        
		    case 3: 
            {
                printf("Pari e dispari\n");
                StringaPariDispari(stringa, pari, dispari);
                printf("\nStringa pari: %s", pari);
                printf("\nStringa dispari: %s", dispari);
                break;
            }
	        
		    case 4: 
            {
                printf("Conta doppioni della stringa\n");
                doppioni = ContaDoppioni(stringa);
                printf("Ci sono %d doppioni", doppioni);
		        break;
            }
		    
		    /*case 5: 
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
		    break;*/
	    }

    }while(scelta<10);

    return 0; 
}