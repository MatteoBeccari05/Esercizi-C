#include <stdio.h>
#include <string.h>

int contaVocali(char stringa[])
{
    int vocali;
    for(int i=0;i<strlen(stringa);i++)
    {
        if(stringa[i]=='a' || stringa[i]=='e'||stringa[i]=='i'||stringa[i]=='o'||stringa[i]=='u')   
        {
            vocali++;
        }
    }
    return vocali;
}

int main(int argc, char *argv[])
{
    int vocali, consonanti, totvocali=0, totconsonanti=0;
    for(int i=0;i<argc;i++)
    {
        vocali=contaVocali(argv[i]);
        consonanti=strlen(argv[i])-vocali;
        totvocali=totvocali+vocali;
        totconsonanti=totconsonanti+consonanti;
    }
    printf("Le vocali sono: %d \nLe consonanti sono: %d",totvocali, totconsonanti);
    return 0;
}