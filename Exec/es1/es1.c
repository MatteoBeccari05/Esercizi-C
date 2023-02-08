/*Scrivere un programma in linguaggio C che usa il comando 
della shell cat per mostrare a video un file di testo
presente in argv[1]

esempio:
$ ./a.out costituzione.txt
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    printf("Errori");
    return -1;
}