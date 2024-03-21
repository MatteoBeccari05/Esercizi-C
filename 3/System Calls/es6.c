#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void Inverso(int argc, char *argv[])
{
    char *tmp;

    for (int i = 0; i < argc; i++)
    {
        for (int j = 3; j < (argc - i - 1); j++)
        {
            if (strcmp("--asc", argv[2]) == 0)
            {
                if (strcmp(argv[j], argv[j + 1]) > 0)
                {
                    tmp = argv[j];
                    argv[j] = argv[j + 1];                      //swap
                    argv[j + 1] = tmp;
                }
            }
            else if (strcmp("--desc", argv[2]) == 0)
            {
                if (strcmp(argv[j], argv[j + 1]) < 0)
                {
                    tmp = argv[j];
                    argv[j] = argv[j + 1];                      //swap 
                    argv[j + 1] = tmp;
                }     
            }
        }
    }
}

int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        printf("Numero argomenti sbagliato\n");
        exit(1);
    }

    Inverso(argc, argv);

    int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    for (int i = 3; i < argc; i++)
    {
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", strlen("\n"));

        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", strlen("\n"));
    }
    close(fd);

    return 0;
}