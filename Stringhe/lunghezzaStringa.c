#include <stdio.h>
#include <string.h>
 
int main()
{
   char lettura[40];  
   int lunghezza,i=0;
   printf("Inserisci una stringa: ");
   fgets(lettura, 40, stdin);    
   while(lunghezza<40 && lettura[lunghezza]!="\0")
   {
       lunghezza++;
   }
   printf("%d",--lunghezza);
 
   return 0;
}
