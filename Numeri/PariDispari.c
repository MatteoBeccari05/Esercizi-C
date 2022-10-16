#include <stdio.h>
int main()
{ 
    int i;
    int array[10];
    printf("Inserire 10 numeri interi:\n");
    for(i=0; i<10; i++)
    {
        printf("Numero %d\n",i+1);
        scanf("%d", &array[i]);
    }
    printf("Numeri pari: \n");
    for(i=0; i<10; i++)
    {
        if(array[i]%2==0)
        {
            printf("%d | ", array[i]);
        }
    }

    printf("Numeri dispari: \n");
    for(i=0; i<10; i++)
    {
        if(array[i]%2!=0)
        {
            printf("%d | ", array[i]);
        }
    }
    printf("\n");
    return 0; 
}