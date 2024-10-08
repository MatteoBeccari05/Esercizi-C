#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100
#define NUMERO_LIBRI 100
#define BUFFER_DIM 1024
#define CATEGORIE 20

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
    if (!file) //errore in apertura del file
    {
        printf("Errore nell'apertura del file");
        exit(0);  //fermo il programma
    }

    // ignora l'intestazione (titolo, autore ecc)
    fgets(buffer, sizeof(buffer), file);

    while (fgets(buffer, sizeof(buffer), file)) 
    {
        Libro libro;
        //leggo dal file csv
        sscanf(buffer, "%99[^,],%99[^,],%d,%f,%99[^\n]", libro.titolo, libro.autore, &libro.anno, &libro.prezzo, libro.categoria);

        // aggiungo il libro all'array di libri
        libri[numLibri++] = libro;

        // controllo se la categoria esiste già
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

        // se la categoria non esiste la creo
        if (trovato == 0 && *numCategorie < CATEGORIE) 
        {
            strcpy(categorie[*numCategorie].nome, libro.categoria);  //creazione categoria
            categorie[*numCategorie].libri[0] = libro;  //aggiungo il libro
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
        //visualizzazione tabellare
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
    printf("\n4)  Modifica la categoria di un libro");
    printf("\n5)  Esporta libri in CSV");
    printf("\n6)  Esci dal programma");
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

/// @brief Visualizza tutte le categorie nel catalogo con il numero di libri
/// @param categorie Array di categorie
/// @param numCategorie numero di categorie
void Visualizzazione_Categorie(Categoria categorie[], int numCategorie) 
{
    printf("\nCategorie disponibili:\n");
    for (int i = 0; i < numCategorie; i++) 
    {
        printf("%d) %s (%d libri)\n", i + 1, categorie[i].nome, categorie[i].numLibri);
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

    if (trovato == 0) //se non trovo il libro desiderato
    {
        printf("Nessun libro trovato con il titolo '%s'\n", titolo_da_cercare);
    }
}

/// @brief Metodo che modifica la categoria di un libro scelto dall'utente
/// @param libri Array di libri
/// @param numLibri numero libri
/// @param categorie array di categorie
/// @param numCategorie 
void ModificaCategoria(Libro libri[], int numLibri, Categoria categorie[], int *numCategorie) 
{
    char titolo_da_modificare[DIM];
    printf("Inserisci il titolo del libro da modificare: ");
    getchar(); // Consuma il newline rimasto
    fgets(titolo_da_modificare, sizeof(titolo_da_modificare), stdin);
    titolo_da_modificare[strcspn(titolo_da_modificare, "\n")] = 0; // Rimuovere il newline

    int trovato = 0;
    for (int i = 0; i < numLibri; i++) 
    {
        if (strcasecmp(libri[i].titolo, titolo_da_modificare) == 0) 
        {
            trovato = 1;


            printf("Categoria attuale: %s\n", libri[i].categoria);  //stampa la categoria attuale

            char nuova_categoria[DIM];
            printf("Inserisci la nuova categoria: "); //inserisco la nuova categoria
            fgets(nuova_categoria, DIM, stdin);
            nuova_categoria[strcspn(nuova_categoria, "\n")] = 0; // Rimuovere il newline

            
            for (int j = 0; j < *numCategorie; j++)     // rimuovo il libro dalla categoria precedente
            {
                if (strcasecmp(categorie[j].nome, libri[i].categoria) == 0) 
                {
                    for (int k = 0; k < categorie[j].numLibri; k++) 
                    {
                        if (strcasecmp(categorie[j].libri[k].titolo, libri[i].titolo) == 0) 
                        {
                            categorie[j].libri[k] = categorie[j].libri[categorie[j].numLibri - 1]; //rimuovo il libro da quella categoria
                            categorie[j].numLibri--;  //diminuisco il numero di libri
                        }
                    }
                }
            }
            
            strcpy(libri[i].categoria, nuova_categoria); // aggiorna la categoria del libro

            // Aggiungi il libro alla nuova categoria
            int categoriaEsistente = 0;
            for (int j = 0; j < *numCategorie; j++) 
            {
                if (strcasecmp(categorie[j].nome, nuova_categoria) == 0) 
                {
                    categorie[j].libri[categorie[j].numLibri++] = libri[i];
                    categoriaEsistente = 1;
                }
            }

            if (categoriaEsistente == 0 && *numCategorie < CATEGORIE)  // se la categoria non esiste la creo
            {
                strcpy(categorie[*numCategorie].nome, nuova_categoria);  //creo la nuova categoria
                categorie[*numCategorie].libri[0] = libri[i];   //inserisco il libro nella nuova categoria
                categorie[*numCategorie].numLibri = 1;  //segno che in questa categoria c'è un libro
                (*numCategorie)++;
            }

            printf("Categoria aggiornata con successo.\n");
            break;
        }
    }

    if (trovato == 0)  //se non trovo il libro cercato dall'utennte
    {
        printf("Nessun libro trovato con il titolo '%s'\n", titolo_da_modificare);
    }
}

/// @brief Crea un file csv con i libri
/// @param nome_file nome del CSV
/// @param libri Array di libri
/// @param numLibri numero di libri
void Esporta_Libri_CSV(const char *nome_file, Libro libri[], int numLibri) 
{
    FILE *file = fopen(nome_file, "w");
    if (!file)  //errore apertura file
    {
        printf("Errore nell'apertura del file per la scrittura.\n");
        return;
    }

    fprintf(file, "Titolo,Autore,Anno,Prezzo,Categoria\n");  //scrivo l'intestazione del CSV

    for (int i = 0; i < numLibri; i++) //scrivo nel csv i file dei libri
    {
        fprintf(file, "\"%s\",\"%s\",%d,%.2f,\"%s\"\n", libri[i].titolo, libri[i].autore, libri[i].anno, libri[i].prezzo, libri[i].categoria);
    }

    fclose(file);
    printf("Dati esportati con successo in '%s'.\n", nome_file);
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
            case 1:
            {
                Visualizzazione_Catalogo_Completo(libri, numLibri);
                break;
            }
                
            case 2:
            {
                Visualizzazione_Categorie(categorie, numeroCategorie);
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
                
            case 3:
            {
                VisualizzazionePerTitolo(libri, numLibri);
                break;
            }
                
            case 4:
            {
                ModificaCategoria(libri, numLibri, categorie, &numeroCategorie);
                break;
            }

            case 5: 
            {
                char nomeFile[DIM];
                printf("Inserisci il nome del file CSV: ");
                getchar(); // Consuma il newline rimasto
                fgets(nomeFile, sizeof(nomeFile), stdin);
                nomeFile[strcspn(nomeFile, "\n")] = 0; // Rimuovi il newline

                Esporta_Libri_CSV(nomeFile, libri, numLibri);
                break;
            }   

            case 6:
            {
                printf("Uscita dal programma.\n");
                break;
            }
                

            default:
                printf("Scelta non valida.\n");
        }

    } while (scelta < 6);

    return 0;

}
