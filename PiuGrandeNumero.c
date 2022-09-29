    #include<stdio.h>  
    void main ()  
    {  
        int array[100];
        int secondoGrande;
        int i;
        int lunghezzaArray;
        int piuGrande;
        printf("Inserisci la lunghezza dell'array: ");  
        scanf("%d",&lunghezzaArray);  
        printf("Inserisci gli elementi dell'array: \n");  
        for(i = 0; i<lunghezzaArray; i++)  
        {  
            scanf("%d",&array[i]);  
        }  
        piuGrande= array[0];  
        secondoGrande = array[1];  
        for(i=0;i<lunghezzaArray;i++)  
        {  
            if(array[i]>piuGrande)  
            {  
                secondoGrande = piuGrande;  
                piuGrande = array[i];  
            }  
            else if (array[i]>secondoGrande && array[i]!=piuGrande)  
            {  
                secondoGrande=array[i];  
            }  
        }  
        printf("Più grande: %d, Secondo più grande: %d \n",piuGrande,secondoGrande);  
          
    }  

