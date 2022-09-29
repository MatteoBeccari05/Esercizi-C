#include<stdio.h>

int main()
{
	int n=0;
    int array[n];
	printf("Inserisci la lunghezza dell'array: \n");
	scanf("%d", &n);

	printf("Inserire i numeri: \n");
	for(int i = 0; i<=n; i++)
	{
		scanf("%d", array[i]);
	}

	printf("I numeri inseriti nell'array sono: \n");
	for(int i = 0; i<=n; i++)
	{
		printf("%d \n", array[i]);
	}

	return 0;
}