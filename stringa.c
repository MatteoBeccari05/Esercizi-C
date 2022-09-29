#include<stdio.h>
#include <string.h>

int main()
{
    int lunghezza;
    char stringa[lunghezza];

    printf("Inserire la lunghezza della stringa: ");
    scanf("%d", &lunghezza);
    lunghezza++;
    printf("Inserire la stringa: ");
    for(int i = 0; i<lunghezza; i++)
    {
        scanf("%c", &stringa[i]);
    }

    printf("La stringa inserita è: ");
    for(int i = 0; i<lunghezza; i++)
    {
        printf("%c", stringa[i]);
    }

}