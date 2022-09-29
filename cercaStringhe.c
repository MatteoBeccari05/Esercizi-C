#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int piped[2];
    pipe(piped);
    int pid = fork();
    int cntTot = 0;
    char vett[1000];
    vett[0] = 'a';
    do
    {
        printf("Che parola vuoi cercare? ");
        scanf("%s", vett);
        if (strcmp(stringa "fine") != 0)
            if (pid == 0) // FIGLIO
            {

                if (strcmp(vett, "fine") != 0) //se sono diverse
                {
                    close(piped[0]); //chiudo la lettura
                    close(1);        //chiudo lo stdout
                    dup(piped[1]);   //va nello std
                    close(piped[1]); //chiudo la scrittura
                    execl("/usr/bin/grep", "grep", argv[1], (char *)0);
                    return -1;
                }

                fopen(file, "r"); //aperto un file in lettura

                if ("fine")
                    close(0);
            }
    } while (/* condition */)
    {
        wait(&pid);
        read();
    }
}