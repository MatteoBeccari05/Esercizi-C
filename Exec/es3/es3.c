/*Scrivere un programma in linguaggio C che usa il comando 
della shell rm per eliminare tutti files presenti
nell'intervallo [argv[1], argv[argc-1]]

esempio:
$ ./a.out /tmp/1.txt /tmp/3.txt /tmp/2.txt
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    int pids[argc - 2];
    for (int i = 1; i < argc; i++)
    {
        pids[i] = fork();
        if (pids[i] == 0)
        {
            execl("/usr/bin/rm", "rm", argv[i], NULL);
            printf("Errori");
            return -1;
        }
    }

    for (int i = 0; i < argc - 2; i++)
    {
        wait(&pids[i]);
    }
    return 0;
}