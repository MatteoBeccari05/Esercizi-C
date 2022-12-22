#include <stdio.h>
#include <string.h>
#define MAX 100

void comuni (FILE *f1, FILE *f2, FILE *f3){
  f1=fopen("f1.txt", "r");
  f2=fopen("f2.txt", "r");
  f3=fopen("risultati.txt", "w");
  strcmp(f1,f2);
  if (f1>f2)
  {
      fprintf(f3,"La stringa più lunga è nel file1 ");
  }
  else if (f2<f1)
  {
       fprintf(f3,"La stringa più lunga è nel file2 ");
  }
  
  fclose(f1);
  fclose(f2);
  fclose(f3);
  }

int main()
{
  FILE *f1,*f2,*f3;
  comuni(f1,f2,f3);
  return 0;
}