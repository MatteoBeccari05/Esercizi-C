#include <stdio.h>

int main(int argc, char *argv[])
{
	int n, i, j = 1;
	do
	{
		printf("Inserisci un numero maggiore di 0 : ");
		scanf("%d", &n);
	} while (n < 0);

	i = n - 1;

	do
	{
		printf("%d+%d=%d\n", j, i, n);
		j++;
		i--;
	} while (j <= n);

	return 0;
}