#include<stdio.h>

int main()
{
    int n,l;
    int array [l];
    printf("Quanti numeri vuoi inserire nell'array? ");
    scanf("%d", &l);

    printf("Inserisci i numeri: \n");
    for(int i = 0; i<l;i++)
    {
        scanf("%d", array[i]);
    }

    printf("Gli elementi dell'array sono: \n");
    for(int i = 0; i<l; i++)
    {
        printf("%c \n", array[i]);
    }
    
}