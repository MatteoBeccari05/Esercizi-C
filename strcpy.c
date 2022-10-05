#include<stdio.h>  
#include <string.h>    
int main()
{    
 char ch[20]={'j', 'a', 'v', 'a', 't', 'p', 'o', 'i', 'n', 't', '\0'};    
   char ch2[20];    
   strcpy(ch2,ch);    
   printf("Value of second string is: %s",ch2);    
 return 0;    
}   
//copiare la stringa