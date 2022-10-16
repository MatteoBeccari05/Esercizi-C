#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	double somma =0;
	for(int i =1;i< argc; i++)
		somma += atoi(argv[i]);
	double media;
	media = somma/(argc-1);
	printf("la media è %f", media);

	return 0;
}
