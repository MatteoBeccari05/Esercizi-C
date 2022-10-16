#include<stdio.h>
int main()
{
   int a = 10;
   int *pt = &a;
   printf("%p \n", &a);  //stampano gli indirizzi
   printf("%p \n", pt);
 
   printf("%d \n", a);  //stampa il valore
   printf("%d \n", *pt); //stampa il contenuto della cella di memoria che ha come indirizzo lo stesso valore della variabile a
}
