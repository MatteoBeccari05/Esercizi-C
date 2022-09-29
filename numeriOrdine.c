#include<stdio.h>    
void main ()    
{    
    int i, j,tmp;     
    int array[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23};     
    for(i = 0; i<10; i++)    
    {    
        for(j = i+1; j<10; j++)    
        {    
            if(array[j] < array[i])    
            {    
                tmp = array[i];    
                array[i] = array[j];    
                array[j] = tmp;     
            }     
        }     
    }     
    printf("Numeri in ordine: \n");    
    for(i = 0; i<10; i++)    
    {    
        printf("%d\n",array[i]);    
    }    
} 