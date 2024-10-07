#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100
#define NUMERO_LIBRI 100
#define BUFFER_DIM 1024
#define CATEGORIE 10

/// @brief Struttura di un libro
typedef struct Libro 
{
    char titolo[DIM];
    char autore[DIM];
    int anno;
    float prezzo;
    char categoria[DIM];
} Libro;

/// @brief Struttura di una categoria di libri
typedef struct Categoria 
{
    char nome[DIM];
    Libro libri[NUMERO_LIBRI];
    int numLibri;
} Categoria;

/// @brief Legge i libri dal file CSV e li inserisce in un array di libri e categorie
/// @param filename Nome del file da cui leggere
/// @param libri Array di libri
/// @param categorie Array di categorie
/// @param numCategorie Puntatore al numero di categorie presenti nel catalogo
/// @return Numero di libri letti
int Lettura_Libri(const char *nome_file, Libro libri[], Categoria categorie[], int *numCategorie) 
{
    char buffer[BUFFER_DIM];
    int numLibri = 0;
    FILE *file = fopen(nome_file, "r");
    if (!file) 
    {
        printf("Errore nell'apertura del file");
        exit(0);
    }

    // Ignora l'intestazione
    fgets(buffer, sizeof(buffer), file);

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
void Visualizzazione_Catalogo_Completo(Libro libri[], int numeroLibri) 
{
    printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");
    printf("| Titolo                                                       | Autore                         | Anno | Prezzo | Categoria             |\n");
    printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");

    for (int i = 0; i < numeroLibri; i++) 
    {
        printf("| %-60s | %-30s | %-4d | %-6.2f | %-20s |\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo, libri[i].categoria);
    }

    printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");
}

/// @brief Stampa il menù di scelta
/// @return Ritorna la scelta dell'utente
int StampaMenu() 
{
    int scelta;
    printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
    printf("\n1)  Visualizza tutti i libri");
    printf("\n2)  Visualizza libri per categoria");
    printf("\n3)  Cerca il titolo di un libro");
    printf("\n4)  Esci dal programma");
    printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

/// @brief Stampa i libri di una determinata categoria
/// @param categoria Categoria da stampare
void Visualizzazione_Per_Categoria(Categoria categoria) 
{
    printf("\nLibri nella categoria '%s':\n", categoria.nome);
    printf("|--------------------------------------------------------------|--------------------------------|------|--------|\n");
    printf("| Titolo                                                       | Autore                         | Anno | Prezzo |\n");
    printf("|--------------------------------------------------------------|--------------------------------|------|--------|\n");

    for (int i = 0; i < categoria.numLibri; i++) 
    {
        printf("| %-60s | %-30s | %-4d | %-6.2f |\n", categoria.libri[i].titolo, categoria.libri[i].autore, categoria.libri[i].anno, categoria.libri[i].prezzo);
    }

    printf("|--------------------------------------------------------------|--------------------------------|------|--------|\n");
}

/// @brief Visualizza le varie categorie presenti nel catalogo
/// @param categorie Struttura di categorie
/// @param numCategorie Numero delle categorie
void VisualizzazioneCategorie(Categoria categorie[], int numCategorie) 
{
    printf("\nCategorie disponibili:\n");
    for (int i = 0; i < numCategorie; i++) 
    {
        printf("%d) %s\n", i + 1, categorie[i].nome);
    }
}

/// @brief Visualizza le caratteristiche di un libro dato il titolo
/// @param libri Array di libri
/// @param numLibri Numero di libri
void VisualizzazionePerTitolo(Libro libri[], int numLibri) 
{
    char titolo_da_cercare[DIM];
    printf("Inserisci il titolo del libro: ");
    getchar(); // Per consumare il newline rimasto
    fgets(titolo_da_cercare, sizeof(titolo_da_cercare), stdin);
    titolo_da_cercare[strcspn(titolo_da_cercare, "\n")] = 0; // Rimuovere il newline

    int trovato = 0;
    for (int i = 0; i < numLibri; i++) 
    {
        if (strcasecmp(libri[i].titolo, titolo_da_cercare) == 0) // Ignora maiuscole e minuscole
        {
            printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");
            printf("| Titolo                                                       | Autore                         | Anno | Prezzo | Categoria             |\n");
            printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");
            printf("| %-60s | %-30s | %-4d | %-6.2f | %-20s |\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo, libri[i].categoria);
            printf("|--------------------------------------------------------------|--------------------------------|------|--------|-----------------------|\n");
            trovato = 1;
            break;
        }
    }

    if (!trovato) //se non trovo il libro desiderato
    {
        printf("Nessun libro trovato con il titolo '%s'\n", titolo_da_cercare);
    }
}

int main(int argc, char *argv[]) 
{
    Categoria categorie[CATEGORIE] = {0};
    Libro libri[NUMERO_LIBRI];
    const char *nome_file = argv[1]; // Nome del file CSV
    int scelta;
    int numeroCategorie = 0;
    int numLibri = Lettura_Libri(nome_file, libri, categorie, &numeroCategorie);

    if (numLibri < 0) 
    {
        exit(0); // Uscita se c'è stato un errore nella lettura
    }

    do 
    {
        scelta = StampaMenu();
        switch (scelta) 
        {
            case 1:  //visualizzo tutti i libri
            {
                Visualizzazione_Catalogo_Completo(libri, numLibri);
                break;
            }
            
            case 2:    //visualizza tutti i libri di una determinata categoria
            {
                VisualizzazioneCategorie(categorie, numeroCategorie);
                printf("Inserisci il numero della categoria: ");
                int n;
                scanf("%d", &n);
                if (n > 0 && n <= numeroCategorie) 
                {
                    Visualizzazione_Per_Categoria(categorie[n - 1]);
                } 
                else 
                {
                    printf("Categoria non valida.\n");
                }
                break;
            }

            case 3:   //visualizza un libro con titolo scelto dall'utente
            {
                VisualizzazionePerTitolo(libri, numLibri);
                break;
            }
                
            case 4:
            {
                printf("Uscita dal programma.\n");
                break;
            }
                
            default:
                printf("Scelta non valida.\n");
        }

    } while (scelta < 4);

    return 0;

}
