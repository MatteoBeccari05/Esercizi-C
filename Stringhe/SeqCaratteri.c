#include<stdio.h>
#include <string.h>

int main()
{
    int tmp;
    char caratteri[tmp];
    printf("Quanti caratteri vuoi inserire? ");
    scanf("%d", &tmp);
    printf("Inserisci una sequenza di caratteri: \n");
    for(int i = 0; i<tmp; i++)
    {
        scanf("%c", &caratteri[i]);
    }


    printf("I caratteri inseriti sono: \n");
    for(int i = 0; i<=tmp; i++)
    {
        printf("%c", caratteri[i]);
    }
    
    
    

}