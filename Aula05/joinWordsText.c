#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    char str[100];

    for (int i = 1; i < argc; i++)
    {
        if (isalpha(argv[i][0])){
            strcat(str, argv[i]);
            strcat(str, " ");
        }
    }

    printf("%s\n", str);
    return EXIT_SUCCESS;
}