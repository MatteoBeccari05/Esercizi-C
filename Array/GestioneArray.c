#include<stdio.h>


void leggi (int *n1, int vett1[])
{ int i;
    do
    {
        printf("Quanti numeri vuoi inserire: \n");
        scanf("%d",n1);
    }while(n1<=0);

    for(i=0;i<*n1;i++)
    {
        printf("Inserisci il %d numero: ",(i+1));
        scanf("%d",&vett1[i]);
    }
}

void stampa (int n1, int vett1[])
{
    int i;
    printf("Vettore:");
    printf("\n");
    for(i=0;i<n1;i++)
    {
        printf(" %d ",vett1[i]);
    }
}

void menu ()
{ 
  printf("1) Somma e media\n");
  printf("2) Stampa numeri pari\n");
  printf("3) Stampa numeri dispari\n");
  printf("4) Vettore invertito\n");
  printf("5) Cerca numero\n");
  printf("6) Ordina Vettore\n");
  printf("7) Elimina numero versione 1\n");
  printf("8) Elimina numero versione 2\n");
  printf("9) Alterna Vettore \n");
  printf("10)Stampa Vettore\n");
  printf("Premere 11 per uscire\n");
  printf("Inserisci una scelta:\n");
}

void inverti (int n1, int vett1[])
{
  int i,k,temp;
  k=n1;
  for (i = 0; i < (n1/2); i++) 
    {
        temp=vett1[i];
        vett1[i]=vett1[k-1];
        vett1[k-1]=temp;
        k--;
    }

  stampa (n1,vett1);
}  

float calcola(int n1, int vett1[])
{ 
    int i,somma=0;
    float med=0.0;
    for(i=0;i<n1;i++)
    {
        somma+=vett1[i];
    }
    med=(float)somma/n1;
    printf("La somma e': %d \n",somma);
    return med;
}   

void pari(int n1, int vett1[])
{ 
    int i;
    printf("\n");
    printf("I numeri pari sono: ");
    printf("\n");
    for(i=0;i<n1;i++)
    {
        if(vett1[i]%2==0)
        {
            printf(" %d \n",vett1[i]);
        }
    }  
}  
 
void dispari(int n1, int vett1[])
{ 
    int i;
    printf("\n");
    printf("I numeri dispari sono: ");
    printf("\n");
    for(i=0;i<n1;i++)
    {
        if(vett1[i]%2==1)
        {
            printf(" %d \n",vett1[i]);
        }
    }  
}  
    
void cerca(int n1, int vett1[])
{ 
    int i,t,cont=0;
    printf("\n");
    printf("Inserisci il numero da ricercare\n");
    scanf("%d",&t);
    for(i=0;i<n1;i++)
    {
        if(vett1[i]==t)
        {
            cont=cont+1;
        }
    }
    printf("\n");
    if(cont>0)
    {
        printf("Il numero %d",t);
        printf("esiste e si ripete %d",cont,"volte");
        printf("\n");
    }
    else 
    {
        printf("Il numero %d",t);
        printf("non esiste nel vettore");
    }      
} 


void ordina(int n1, int vett1[])
{ 
    int i,t,k,cont=0,app;   
    for (k=0; k<n1-1; k++)
    {
        for (i=k+1;i<n1;i++)
        {
            if (vett1[k]<vett1[i])
            {
               app=vett1[k];
               vett1[k]=vett1[i];
               vett1[i]=app;
            }       
        }
    } 
    stampa (n1,vett1);
}  


void elimina1(int n1, int vett1[])
{ 
    int i,t,k=0,cont=0,pos,vett2[100];
    printf("\n");
    printf("Inserisci il numero da eliminare");
    scanf("%d",&t);
    for(i=0;i<n1;i++)
    {
        if(vett1[i]!=t)
        {
          vett2[k]=vett1[i];
          k=k+1;              
        }
    }   
    if(k>0)
    {
        printf("Il numero %d",t);
        printf("esiste e si ripete %d",(n1-k));
        printf("volte");
        printf("\n");
    }
    else
    {
        printf("Il numero %d",t);
        printf("non esiste nel vettore");
    }  
    for(i=0;i<k;i++)
    {
        printf("\n");
        printf("%d",vett2[i]);
    }    
}  
  
void elimina2(int n1, int vett1[])
{ 
    int i,t,k=0,pos=0,j=0;
    printf("\n");
    printf("Inserisci il numero da eliminare");
    scanf("%d",&t);
    for(i=0;i<n1;i++)
    {
        if(vett1[i]==t)
        {
         pos=i;
         k=k+1;

            for(j=pos;j<n1-1;j++)
            {
                vett1[j]=vett1[j+1];  
            }              
        }
    }   
    if(k>0)
    {
        printf("Il numero %d",t);
        printf("esiste e si ripete %d",k);
        printf("volte");
        printf("\n");
    }
    else 
    {
        printf("Il numero %d",t);
        printf("non esiste nel vettore");
    }  
    for(i=0;i<(n1-k);i++)
    {
        printf("\n");
        printf("%d",vett1[i]);
    }    
}  


void alterna(int n1, int vett1[])
{ 
    int i,t,app;   
    for (i=0; i<n1-1; i=i+2)
    {
        app=vett1[i];
        vett1[i]=vett1[i+1];
        vett1[i+1]=app;
    }
    stampa (n1,vett1); 
}


int main()
{
    int a,b,vett[100];
    leggi(&a,vett);
    printf("\n");
    do
    {
        menu();
        scanf("%d", &b);
        switch (b)
	    {
            case 1: 
		    printf("Somma e media\n");
		    printf("La media e': %f \n",calcola(a,vett));
		    break; 
		    case 2: 
	        pari(a, vett);
		    break;
		    case 3: 
	        dispari(a, vett);
		    break;
		    case 4: 
		    inverti (a, vett);
		    break;
		    case 5: 
		    cerca(a, vett);
		    break;
		    case 6: 
		    ordina(a, vett);
		    break;
		    case 7: 
		    elimina1(a, vett);
		    break;
		    case 8: 
		    elimina2(a, vett);
		    break;
		    case 9: 
		    alterna(a, vett);
		    break;
		    case 10: 
		    stampa(a, vett);
		    break;
		    default: 
		    printf("Esci\n");
		    break;
	    }  
        system("pause");
    }while(b<11);
    return 0; 
}
