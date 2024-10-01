#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define DIM1 20

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

int LunghezzaStringhe(char stringa1[], char stringa2[])
{
    if (strlen(stringa1) > strlen(stringa2))
    {
        return 1;
    }
    else if (strlen(stringa2) > strlen(stringa1))
    {
        return 2;
    }   
    return -1;
}

void TrovaLettereComuni(char stringa1[], char stringa2[], char arrayLettereComuni[])
{
    int contatore = 0;
    int inserisci = 1;
    for (int i = 0; i < strlen(stringa1); i++)
    {
        for (int k = 0; k < strlen(stringa2); k++)
        {
            if (stringa1[i] == stringa2[k])
            {
                arrayLettereComuni[contatore++] = stringa1[i];
            }
        }
    }
}

int ContaVocali(char stringa[])
{
    int vocali = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == 'a' || stringa[i] == 'e' || stringa[i] == 'i' || stringa[i] == 'o' || stringa[i] == 'u')
        {
            vocali++;
        }
    }
    return vocali;
}

int ContaConsonanti(char stringa[])
{
    int consonanti = 0;
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] != 'a' || stringa[i] != 'e' || stringa[i] != 'i' || stringa[i] != 'o' || stringa[i] != 'u')
        {
            consonanti++;
        }
    }
    return consonanti;
}

int main(int argc, char *argv[])
{
    char stringa[DIM1], dispari[DIM1], pari[DIM1];
    int scelta, frequenza, doppioni;
    char lettereDaCercare;
    char stringaPiuLunga;
    int secondaStringa;
    char stringa2[DIM1];
    char arrayLettereComuni[DIM1];
    int v1, v2, c1, c2;

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
		    
		    case 5: 
            {
                printf("\nInserisci una nuova stringa\n");
                secondaStringa = 1;
                scanf("\n");
                fgets(stringa2, DIM1, stdin);
                break;
            }
		    
		    case 6: 
            {
                if(secondaStringa == 0)
                {
                    printf("\nPrima inserire la seconda stringa\n");
                }
                else
                {
                    stringaPiuLunga = LunghezzaStringhe(stringa, stringa2);
                    if (secondaStringa == -1)
                    {
                        printf("\nLe due stringhe hanno la stessa lunghezza\n");
                    }
                    
                    else
                    {
                        printf("\nLa stringa più lunga è: %d\n", stringaPiuLunga);
                    } 
                }
                break;
            }
		    
		    case 7: 
            {
                if(secondaStringa == 0)
                {
                    printf("\nPrima inserire la seconda stringa\n");
                }
                else
                {
                    printf("\nLettere in comune:\n");
                    TrovaLettereComuni(stringa, stringa2, arrayLettereComuni);
                    printf("Le lettere in comune sono: %s\n", arrayLettereComuni);
                }
            }
		    
		    case 8: 
            {
                if(secondaStringa == 0)
                {
                    printf("\nPrima inserire la seconda stringa\n");
                }
                else
                {
                    v1 = ContaVocali(stringa);
                    v2 = ContaVocali(stringa2);
                    if (v1 > v2)
                    {
                        printf("\nLa prima stringa contiene più vocali\n");
                    }
                    
                    else if (v2 > v1)
                    {
                        printf("\nLa seconda stringa contiene più vocali\n");
                    }
                    
                    else
                    {
                        printf("\nLe stringhe contengono la stessa quantità di vocali\n");
                    }
                }
		        break;
            }
		    
		    case 9: 
            {
                if(secondaStringa == 0)
                {
                    printf("\nPrima inserire la seconda stringa\n");
                }
                else
                {
                    c1 = ContaConsonanti(stringa);
                    c1 = ContaConsonanti(stringa2);
                    if (c1 > c2)
                    {
                        printf("\nLa prima stringa contiene più vocali\n");
                    }
                    
                    else if (c2 > c1)
                    {
                        printf("\nLa seconda stringa contiene più vocali\n");
                    }
                    
                    else
                    {
                        printf("\nLe stringhe contengono la stessa quantità di vocali\n");
                    }
                }
		        break;
            }
	    }
        
    }while(scelta<10);

    return 0; 
}