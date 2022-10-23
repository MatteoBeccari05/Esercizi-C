#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int contiene_lettere(char stringa[])
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

int conta_frequenza(char stringa[], char carattere)
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

void crea_stringhe(char stringa[], char stringa_pari[], char stringa_dispari[])
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

int verifica_doppie(char stringa[])
{
    int doppie = 0;
    for (int i = 1; i < strlen(stringa); i++)
    {
        if (stringa[i - 1] == stringa[i])
        {
            doppie++;
        }
    }
    return doppie;
}

int confronto_lunghezza(char stringa1[], char stringa2[])
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
    int vocali_parola = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
            vocali_parola++;
    }
    return vocali_parola;
}

int conta_consonanti(char parola[])
{
    int consonanti_parola = 0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] != 'a' && parola[i] != 'e' && parola[i] != 'i' && parola[i] != 'o' && parola[i] != 'u')
            consonanti_parola++;
    }
    return consonanti_parola;
}

int main(int argc, char *argv[])
{
    int dimensione = 10;
    char stringa[dimensione];
    char stringa2[dimensione];
    char array_comune[dimensione];
    char stringa_pari[dimensione / 2];
    char stringa_dispari[dimensione / 2];
    char lettera;
    int frequenza;
    int i = 0;
    printf("Inserisci una stringa:\n");
    fgets(stringa, dimensione, stdin);
    for (int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = tolower(stringa[i]);
    }
    int selezione, doppie, stringa2inserita = 0, piu_lunga, vocali1, vocali2, consonanti1, consonanti2;
    do
    {
        printf("\n1) Contiene solo lettere");
        printf("\n2) Conta frequenza di una lettera");
        printf("\n3) Crea due stringhe");
        printf("\n4) Verifica le doppie");
        printf("\n5) Inserisci un'altra stringa");
        printf("\n6) Stringa più lunga");
        printf("\n7) Quali lettere sono presenti in entrambi le stringhe");
        printf("\n8) Quale contiene più vocali");
        printf("\n9) Quale contiene più consonanti");
        printf("\nSelezione: ");
        scanf("%d", &selezione);
        switch (selezione)
        {
        case 1:
            printf("Contiene solo lettere: ");
            if (contiene_lettere(stringa) == 1)
            {
                printf("si\n");
            }
            else
                printf("no\n");
            break;
        case 2:
            printf("Conta frequenza di una lettera\n");
            printf("Inserisci lettera: ");
            scanf("\n%c", &lettera);
            frequenza = conta_frequenza(stringa, lettera);
            printf("\nLa frequenza della lettera %c è di %d\n", lettera, frequenza);
            break;
        case 3:
            printf("Crea due stringhe\n");
            crea_stringhe(stringa, stringa_pari, stringa_dispari);
            printf("\nStringa pari: %s", stringa_pari);
            printf("\nStringa dispari: %s", stringa_dispari);
            break;
        case 4:
            printf("Verifica le doppie");
            doppie = verifica_doppie(stringa);
            printf("\nCi sono %d coppie di doppie\n", doppie);
            break;
        case 5:
            printf("\nInserisci una nuova stringa\n");
            stringa2inserita = 1;
            scanf("\n");
            fgets(stringa2, dimensione, stdin);
            break;
        case 6:
            if (stringa2inserita == 0)
                printf("\nPrima inserire la seconda stringa\n");
            else
            {
                piu_lunga = confronto_lunghezza(stringa, stringa2);
                if (piu_lunga == -1)
                    printf("\nLe due stringhe hanno la stessa lunghezza\n");
                else
                    printf("\nLa stringa più lunga è la stringa %d\n", piu_lunga);
            }
            break;
        case 7:
            if (stringa2inserita == 0)
                printf("\nPrima inserire la seconda stringa\n");
            else
            {
                printf("\nLettere in comune:\n");
                lettere_comuni(stringa, stringa2, array_comune);
                printf("Le lettere in comune sono: %s\n", array_comune);
            }

            break;
        case 8:
            if (stringa2inserita == 0)
                printf("\nPrima inserire la seconda stringa\n");
            else
            {
                vocali1 = conta_vocali(stringa);
                vocali2 = conta_vocali(stringa2);
                if (vocali1 > vocali2)
                    printf("\nLa prima stringa contiene più vocali\n");
                else if (vocali2 > vocali1)
                    printf("\nLa seconda stringa contiene più vocali\n");
                else
                    printf("\nLe stringhe contengono la stessa quantità di vocali\n");
            }
            break;
        case 9:
            if (stringa2inserita == 0)
                printf("\nPrima inserire la seconda stringa\n");
            else
            {
                consonanti1 = conta_consonanti(stringa);
                consonanti2 = conta_consonanti(stringa2);
                if (consonanti1 > consonanti2)
                    printf("\nLa prima stringa contiene più consonanti\n");
                else if (consonanti2 > consonanti1)
                    printf("\nLa seconda stringa contiene più consonanti\n");
                else
                    printf("\nLe stringhe contengono la stessa quantità di consonanti\n");
            }
            break;
        default:
            return 0;
            break;
        }
    } while (1);
}