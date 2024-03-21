#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura student_t
struct student_t 
{
    char cognome[50];
    char nome[50];
    float media;
};

int main() 
{
    // Creazione di un array di tre puntatori a struct student_t
    struct student_t *studenti[3];

    // Allocazione della memoria per ciascuno studente
    for (int i = 0; i < 3; i++)
    {
        studenti[i] = (struct student_t *)malloc(sizeof(struct student_t));
        if (studenti[i] == NULL) 
        {
            printf("Errore nell'allocazione di memoria.\n");
            return 1;
        }
    }

    // Inserimento dei dati dei tre studenti
    for (int i = 0; i < 3; i++) 
    {
        printf("Inserisci il cognome dello studente %d: ", i + 1);
        scanf("%s", studenti[i]->cognome);

        printf("Inserisci il nome dello studente %d: ", i + 1);
        scanf("%s", studenti[i]->nome);

        printf("Inserisci la media dello studente %d: ", i + 1);
        scanf("%f", &studenti[i]->media);
    }

    // Stampa il contenuto delle tre strutture referenziate dall'array
    for (int i = 0; i < 3; i++) 
    {
        printf("\nStudente %d:\n", i + 1);
        printf("Cognome: %s\n", studenti[i]->cognome);
        printf("Nome: %s\n", studenti[i]->nome);
        printf("Media: %.2f\n", studenti[i]->media);
    }

    // Stampa il contenuto dell'array (gli indirizzi di memoria)
    printf("Indirizzi di memoria degli studenti:\n");
    for (int i = 0; i < 3; i++) 
    {
        printf("%p\n", (void *)studenti[i]);
    }

    // Liberazione della memoria allocata
    for (int i = 0; i < 3; i++)
    {
        free(studenti[i]);
    }

    return 0;
}