#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGA 100
#define LIBRI 100
#define BUFFER_DIM 1024
#define CATEGORIE 10

/// @brief Struttura di un libro
typedef struct Libro 
{
    char titolo[MAX_STRINGA];
    char autore[MAX_STRINGA];
    int anno;
    float prezzo;
    char categoria[MAX_STRINGA];
} Libro;

/// @brief Struttura di una categoria di libri
typedef struct Categoria 
{
    char nome[MAX_STRINGA];
    Libro libri[LIBRI];
    int numLibri;
} Categoria;

/// @brief Legge i libri dal file CSV e li inserisce in un array di libri e categorie
/// @param filename Nome del file da cui leggere
/// @param libri Array di libri
/// @param categorie Array di categorie
/// @param numCategorie Puntatore al numero di categorie presenti nel catalogo
/// @return Numero di libri letti
int leggiLibriDaFile(const char *filename, Libro libri[], Categoria categorie[], int *numCategorie) 
{
    char buffer[BUFFER_DIM];
    FILE *file = fopen(filename, "r");
    if (!file) 
    {
        perror("Errore nell'apertura del file");
        return -1; // Restituisci -1 in caso di errore
    }

    // Ignora l'intestazione
    fgets(buffer, sizeof(buffer), file);
    
    int numLibri = 0;

    while (fgets(buffer, sizeof(buffer), file)) 
    {
        Libro libro;
        sscanf(buffer, "%99[^,],%99[^,],%d,%f,%99[^\n]", libro.titolo, libro.autore, &libro.anno, &libro.prezzo, libro.categoria);

        // Aggiungi il libro all'array di libri
        libri[numLibri++] = libro;

        // Controlla se la categoria esiste già
        int trovato = 0;
        for (int i = 0; i < *numCategorie; i++) 
        {
            if (strcmp(categorie[i].nome, libro.categoria) == 0) 
            {
                categorie[i].libri[categorie[i].numLibri++] = libro;
                trovato = 1;
                break;
            }
        }

        // Se la categoria non esiste, la creo
        if (!trovato && *numCategorie < CATEGORIE) 
        {
            strcpy(categorie[*numCategorie].nome, libro.categoria);
            categorie[*numCategorie].libri[0] = libro;
            categorie[*numCategorie].numLibri = 1;
            (*numCategorie)++;
        }
    }
    fclose(file);
    return numLibri; // Restituisci il numero di libri letti
}

/// @brief Visualizza a schermo tutti i libri
/// @param libri Array di libri
/// @param n Numero di libri
void VisualizzaTuttiLibri(Libro libri[], int n) 
{
    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");
    printf("| Titolo                                             | Autore               | Anno | Prezzo | Categoria             |\n");
    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");

    for (int i = 0; i < n; i++) 
    {
        printf("| %-50s | %-20s | %-4d | %-6.2f | %-20s |\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo, libri[i].categoria);
    }

    printf("|----------------------------------------------------|----------------------|------|--------|-----------------------|\n");
}

/// @brief Stampa il menù di scelta
/// @return Ritorna la scelta dell'utente
int Menu() 
{
    int scelta;
    printf("\n============================================================");
    printf("\n1)  Visualizza tutti i libri");
    printf("\n2)  Visualizza libri per categoria");
    printf("\n3)  Esci dal programma");
    printf("\n============================================================\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

/// @brief Stampa i libri di una determinata categoria
/// @param categoria Categoria da stampare
void VisualizzaLibriPerCategoria(Categoria categoria) 
{
    printf("\nLibri nella categoria '%s':\n", categoria.nome);
    printf("|----------------------------------------------------|----------------------|------|--------|\n");
    printf("| Titolo                                             | Autore               | Anno | Prezzo |\n");
    printf("|----------------------------------------------------|----------------------|------|--------|\n");

    for (int i = 0; i < categoria.numLibri; i++) 
    {
        printf("| %-50s | %-20s | %-4d | %-6.2f |\n", categoria.libri[i].titolo, categoria.libri[i].autore, categoria.libri[i].anno, categoria.libri[i].prezzo);
    }

    printf("|----------------------------------------------------|----------------------|------|--------|\n");
}

/// @brief Visualizza le varie categorie presenti nel catalogo
/// @param categorie Struttura di categorie
/// @param numCategorie Numero delle categorie
void VisualizzaCategorie(Categoria categorie[], int numCategorie) 
{
    printf("\nCategorie disponibili:\n");
    for (int i = 0; i < numCategorie; i++) 
    {
        printf("%d) %s\n", i + 1, categorie[i].nome);
    }
}

int main() 
{
    Categoria categorie[CATEGORIE] = {0};
    Libro libri[LIBRI];
    const char *filename = "libri.csv"; // Nome del file CSV
    int scelta;
    int numeroCategorie = 0;
    int numLibri = leggiLibriDaFile(filename, libri, categorie, &numeroCategorie);

    if (numLibri < 0) 
    {
        exit(0); // Uscita se c'è stato un errore nella lettura
    }

    do 
    {
        scelta = Menu();
        switch (scelta) 
        {
            case 1:  //visualizzo tutti i libri
            {
                VisualizzaTuttiLibri(libri, numLibri);
                break;
            }
            
            case 2:    //visualizza tutti i libri di una determinata categoria
            {
                VisualizzaCategorie(categorie, numeroCategorie);
                printf("Inserisci il numero della categoria: ");
                int n;
                scanf("%d", &n);
                if (n > 0 && n <= numeroCategorie) 
                {
                    VisualizzaLibriPerCategoria(categorie[n - 1]);
                } else 
                {
                    printf("Categoria non valida.\n");
                }
                break;
            }
                
            case 3:
            {
                printf("Uscita dal programma.\n");
                break;
            }
                
            default:
                printf("Scelta non valida.\n");
        }

    } while (scelta < 3);

    return 0;
}
