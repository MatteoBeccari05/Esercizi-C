#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGA 100
#define LIBRI 100

typedef struct Libro 
{
    char titolo[MAX_STRINGA];
    char autore[MAX_STRINGA];
    int anno;
    float prezzo;
    char categoria[MAX_STRINGA];
} Libro;

int leggiLibriDaFile(const char *filename, Libro libri[]) 
{
    int n = 0;
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        perror("Errore nell'apertura del file");
        return -1;
    }

    char buffer[256];
    // Ignora l'intestazione
    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file) && n < LIBRI) 
    {
        sscanf(buffer, "%99[^,],%99[^,],%d,%f,%99[^\n]",
               libri[n].titolo,
               libri[n].autore,
               &libri[n].anno,
               &libri[n].prezzo,
               libri[n].categoria);
        n++;
    }
    fclose(file);
    return n; // Restituisci il numero di libri letti
}

void VisualizzaLibri(Libro libri[], int n) 
{
    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");
    printf("| Titolo                                             | Autore               | Anno | Prezzo | Categoria             |\n");
    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");

    for (int i = 0; i < n; i++) {
        printf("| %-50s | %-20s | %-4d | %-6.2f | %-20s |\n",
               libri[i].titolo,
               libri[i].autore,
               libri[i].anno,
               libri[i].prezzo,
               libri[i].categoria);
    }

    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");
}

int Menu() 
{
    int scelta;
    printf("\n============================================================");
    printf("\n1)  Visualizza tutti i libri");
    printf("\n2)  Visualizza libri per categoria (non implementato)");
    printf("\n3)  Esci dal programma");
    printf("\n============================================================\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int main() 
{
    Libro libri[LIBRI];
    const char *filename = "libri.csv"; // Nome del file CSV
    int scelta;
    int numLibri = leggiLibriDaFile(filename, libri);

    if (numLibri < 0)
    {
        return 1; // Uscita se c'è stato un errore nella lettura
    }

    do 
    {
        scelta = Menu();

        switch (scelta) 
        {
            case 1:
            {
                VisualizzaLibri(libri, numLibri);
                break;
            }
                
            case 2:
            {
                printf("Funzione non implementata.\n");
                break;
            }
                
            case 3:
            {
                printf("Uscita dal programma.\n");
                break;
            }

        }

    } while (scelta < 3);

    return 0;
}
