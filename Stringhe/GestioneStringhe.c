#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define DIM1 10
#define DIM2 5

int VerificaLettere(char stringa[])
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

int FrequenzaLettere(char stringa[], char carattere)
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

void Pari_Dispari(char stringa[], char stringa_pari[], char stringa_dispari[])
{
    int k = 0, t = 0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (i % 2 == 0)
        {
            stringa_pari[k] = stringa[i];
            k++;
        }
        else
        {
            stringa_dispari[t] = stringa[i];
            t++;
        }
    }
}

int Doppioni(char stringa[])
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
        return 1;
    else if (strlen(stringa2) > strlen(stringa1))
        return 2;
    return -1;
}

void lettere_comuni(char stringa1[], char stringa2[], char comune[])
{
    int contatore = 0;
    int inserisci = 1;
    for (int i = 0; i < strlen(stringa1); i++)
    {
        for (int k = 0; k < strlen(stringa2); k++)
        {
            if (stringa1[i] == stringa2[k])
                comune[contatore++] = stringa1[i];
        }
    }
}

int conta_vocali(char parola[])
{
    int vocali = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
            vocali++;
    }
    return vocali;
}

int conta_consonanti(char parola[])
{
    int consonanti= 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] != 'a' && parola[i] != 'e' && parola[i] != 'i' && parola[i] != 'o' && parola[i] != 'u')
        {
            consonanti++;
        }    
    }
    return consonanti;
}

int main(int argc, char *argv[])
{
    char stringa[DIM1];
    char stringa2[DIM1];
    char array_comune[DIM1];
    char stringa_pari[DIM2];
    char stringa_dispari[DIM2];
    char lettera;
    int i = 0, scelta, doppioni, stringaInserita2 = 0, StringaLunga, Svocali1, Svocali2, consonanti1, consonanti2, freq;
	
    printf("Inserisci una stringa:\n");
    fgets(stringa, DIM1, stdin);
    for (int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = tolower(stringa[i]);
    }
    
    do
    {
        printf("\n1) Verifica se la stringa contiene solo lettere");
        printf("\n2) Verificare la frequenza di una lettera");
        printf("\n3) Crea due stringhe: Pari e Dispari");
        printf("\n4) Verifica le doppie nella stringa");
        printf("\n5) Inserire un'altra stringa");
        printf("\n6) Stringa più lunga");
        printf("\n7) Cerca lettere nelle due stringhe");
        printf("\n8) Quale stringa contiene più vocali");
        printf("\n9) Quale stringa contiene più consonanti");
        printf("\nPremere 0 per terminare il programma");
        printf("\nSelezione: ");
        scanf("%d", &scelta);
        switch (scelta)
        {
            case 1:
            {
                printf("Contiene solo lettere: ");
                if (VerificaLettere(stringa) == 1)
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
                printf("Conta frequenza di una lettera\n");
                printf("Inserisci lettera: ");
                scanf("\n%c", &lettera);
                freq = FrequenzaLettere(stringa, lettera);
                printf("\nLa frequenza della lettera %c è di %d\n", lettera, freq);
                break;
            }
            
            case 3:
            {
                printf("Pari e dispari\n");
                Pari_Dispari(stringa, stringa_pari, stringa_dispari);
                printf("\nStringa pari: %s", stringa_pari);
                printf("\nStringa dispari: %s", stringa_dispari);
                break;
            }
            
            case 4:
            {
                printf("Verificare i doppioni presenti nella stringa");
                doppioni = Doppioni(stringa);
                printf("\nCi sono %d doppioni\n", doppioni);
                break;
            }
            
            case 5:
            {
                printf("\nInserisci una nuova stringa\n");
                stringaInserita2= 1;
                scanf("\n");
                fgets(stringa2, DIM1, stdin);
                break;
            }

            
            case 6:
            {
                if (stringaInserita2 == 0)
                {
                    printf("\nPrima inserire la seconda stringa\n");
                }
                
                else
                {
                    StringaLunga = LunghezzaStringhe(stringa, stringa2);
                    if (StringaLunga == -1)
                    {
                        printf("\nLe due stringhe hanno la stessa lunghezza\n");
                    }
                    
                    else
                    {
                        printf("\nLa stringa più lunga è: %d\n", StringaLunga);
                    } 
                }
                break;
            }
            
            case 7:
            {
                if (stringaInserita2 == 0)
                {
                    printf("\nInserire la seconda stringa\n");
                }
                
                else
                {
                    printf("\nLettere in comune:\n");
                    lettere_comuni(stringa, stringa2, array_comune);
                    printf("Le lettere in comune sono: %s\n", array_comune);
                }

                break;
            }
            
            case 8:
            {
                if (stringaInserita2 == 0)
                {
                    printf("\nInserire la seconda stringa\n");
                }
                
                else
                {
                    Svocali1 = conta_vocali(stringa);
                    Svocali2 = conta_vocali(stringa2);
                    if (Svocali1 > Svocali2)
                    {
                        printf("\nLa prima stringa contiene più vocali\n");
                    }
                    
                    else if (Svocali2 > Svocali1)
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
                if (stringaInserita2 == 0)
                {
                    printf("\nInserire la seconda stringa\n");
                }
                
                else
                {
                    consonanti1 = conta_consonanti(stringa);
                    consonanti2 = conta_consonanti(stringa2);
                    if (consonanti1 > consonanti2)
                    {
                        printf("\nLa prima stringa contiene più consonanti\n");
                    }
                    
                    else if (consonanti2 > consonanti1)
                    {
                        printf("\nLa seconda stringa contiene più consonanti\n");
                    }
                    
                    else
                    {
                        printf("\nLe stringhe contengono la stessa quantità di consonanti\n");
                    }
                    
                }
                break;
            }
            
            default:
            return 0;
            break;
        }
    } while (1);
}