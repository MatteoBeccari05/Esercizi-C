#include<stdio.h>

int main()
{
    __int8_t i=5;
    __int8_t *pt=&i;
    printf("%d \n",i);  //stampa il valore della variabile i
    printf("%d \n",*pt);  //stampa il valore di del puntatore

    printf("%p \n", &i);       //stampa l'indirizzo di memoria di i
    printf("%p \n", &pt);      //stampa l'indirizzo 
}