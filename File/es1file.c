#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */
int main()
{ FILE *f1;
  char P[MAX], S[MAX];
  int cont=0;
  f1=fopen("F1.txt", "r");
  if (f1==NULL){
    printf("Errore apertura del file!\n");
  return 0;
  }
  printf("\nParola da cercare ? ");
  scanf("%s", P);
  while (!feof(f1))
  { fscanf(f1, "%s", S);
    if (strcmp(S,P)==0){
     printf("\nHo trovato %s!\n", P);
     cont++;
    }
  }
  printf("Trovata %s %d volte \n", P, cont);
  fclose(f1);
}
