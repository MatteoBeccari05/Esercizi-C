#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main() {
    typedef struct {
      char nome[20]; 
      char cognome[20];
      int media;   

   } student_t;

   student_t *stud;
   stud= malloc(sizeof(student_t));  //Memory ALLOCation
   
   strcpy(stud->nome,"nome"); // -> notazione per accedere ai membri della struttura quando la variabile è un puntatore
   strcpy(stud->cognome,"cognome");
   stud->media=8;
   
   printf("%s\n",stud->cognome);
   printf("%s\n",stud->nome);
   printf("%d\n",stud->media);

   free(stud);  //memory de-allocation
}
