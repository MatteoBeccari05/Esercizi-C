/*Scriva un programma C che dato un array prestabilito, prenda in input da
riga di comando un numero e lo ricerchi all'interno dell'array.
La ricerca deve essere demandata ad un processo figlio e deve essere
implementata attraverso un'apposita funzione di nome ricerca.*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/fcntl.h>
#include <ctype.h>
#include <string.h>

int ricerca(int numeri[], int n, int numero)
{

	for (int i = 0; i < n; i++)
	{
		if (numeri[i] == numero)
		{
			return i;
		}
	}

	return -1;
}

int main(int argc, char *argv[])
{

	int numeri[] = {10, 20, 30};
	int numero = atoi(argv[1]);
	int posizione;

	int pid = fork();

	if (pid == 0)
	{
		posizione = ricerca(numeri, 3, numero);

		if (posizione > -1)
			printf("\n\nil numero %d si trova in posizione %d nell'array \n\n", numero, posizione);
		else
			printf("\n\nIl numero %d non è presente nell'array\n\n", numero);

		exit(1);
	}

	wait(&pid);

	return 0;
}