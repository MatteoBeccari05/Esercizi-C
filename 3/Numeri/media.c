#include <stdio.h>
#include <string.h>

int main()
{
    int a;
    int b;
    double input;
    double numeriInseriti=0;
    double totale=0;
    printf("Inserire i due numeri limite: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Inserire i numeri per il calcolo della media: \n");
    do{
        scanf("%le", &input);
        numeriInseriti++;
        totale+=input;
    }while(input<=b && input >=a);
    printf("Media dei valori: %f", (float)(totale-=input)/--numeriInseriti);
    return 0;
}
