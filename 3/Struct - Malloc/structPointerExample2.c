#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int i;
void main() {
   int const DIM =3;
    typedef struct {
      char nome[20]; 
      char cognome[20];
      int media;   

   } student_t;

   student_t *classePtr[DIM];  //array di puntatori a student_t
   for (i=0;i<DIM;i++) {
      classePtr[i]=malloc(sizeof(student_t)); //Memory ALLOCation
      printf("inserisci il nome...\n");
      scanf("%s", &classePtr[i]->nome);  // -> notazione per accedere ai membri della struttura quando la variabile è un puntatore
      printf("inserisci il cognome...\n");
      scanf("%s", &classePtr[i]->cognome);
      printf("inserisci il media...\n");
      scanf("%d",&classePtr[i]->media);
   }


   for (i=0;i<DIM;i++) {
      printf("%s %s ","nome:",classePtr[i]->nome);
      printf("%s %s ","cognome:",classePtr[i]->cognome);
      printf("%s %d\n","media:",classePtr[i]->media);
      free(classePtr[i]);  //Memory de-allocation
   }
}
