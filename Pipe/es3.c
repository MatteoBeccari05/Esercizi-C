/*Il padre crea 2 figli: P1 e P2.
P1 chiede in input da tastiera un numero intero e lo manda al processo P2
usando una pipe p1p2.
Il processo P2 calcola il quadrato e lo stampa a video usando la system
call write.

Suggerimento: usare la funzione sprintf per convertire da intero a stringa

Esempio:
$ ./a.out                                                                                     master ✗
Inserisci un numero: 4
16
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

    int pid, p1p2[2];
    pipe(p1p2);

    pid = fork();

    if (pid == 0)
    {
        close(p1p2[0]);
        int numero;
        printf("Inserisci un numero: ");
        scanf("%d", &numero);
        write(p1p2[1], &numero, sizeof(numero));
        exit(0);
    }

    pid = fork();

    if (pid == 0)
    {
        int numero;
        char quadrato[10];
        close(p1p2[1]);
        read(p1p2[0], &numero, sizeof(numero));
        numero = numero * numero;
        close(p1p2[0]);

        sprintf(quadrato, "%d", numero);

        write(1, quadrato, strlen(quadrato));
        write(1, "\n", strlen("\n"));
        exit(0);
    }

    wait(&pid);
    wait(&pid);

    return 0;
}