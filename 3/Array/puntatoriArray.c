#include<stdio.h>

int main()
{
    char caratteri[5];
    char *pt=&caratteri;

    printf("Inserisci  5 caratteri: \n");
    for(int i=0;i<6;++i)
    {
        scanf("%c", caratteri+i);
    }


    printf("Elementi dell'array: \n");
    for(int i=0;i<6;++i)
    {
        printf("%c \n", *(caratteri+i));
    }
    return 0;

}
