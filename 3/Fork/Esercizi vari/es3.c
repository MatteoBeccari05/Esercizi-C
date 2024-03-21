/*Data una stringa letta da riga di comando si scriva un programma in linguaggio C
che istanzi un processo figlio il quale converta la stringa da minuscolo a maiuscolo

esempio di esecuzione:
$./a.out ciao
la stringa in maiuscolo è CIAO*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

void converti(char str[])
{
	int i, n = strlen(str);
	for (i = 0; i < n; i++)
	{
		str[i] = toupper(str[i]);
	}
}

int main(int argc, char *argv[])
{

	char str[strlen(argv[1])];

	int pid = fork();

	if (pid == 0)
	{
		strcpy(str, argv[1]);
		converti(str);
		printf("la stringa in maiuscolo è: %s\n\n", str);
		sleep(5);
		exit(2);
	}
	else
	{
		wait(&pid);
	}

	printf("\n\nMio figlio ha terminato\n\n");
	return 0;
}