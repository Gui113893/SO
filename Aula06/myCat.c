#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man fopen
 man fgets
*/

#define LINEMAXSIZE 40 /* or other suitable maximum line size */


int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 
    int i,count,complete;

    /* Validate number of arguments */
    if( argc < 2 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    /* Open the file provided as argument */
    for (i = 1; i < argc; i++)
    {
        printf("\nOpening file %s\n", argv[i]);
        errno = 0;
        fp = fopen(argv[i], "r");
        if( fp == NULL )
        {
            perror ("Error opening file!");
            return EXIT_FAILURE;
        }

        /* Read all the lines of the file */
        count = 1;
        complete = 1;
        while( fgets(line, sizeof(line), fp) != NULL )
        {
            if (complete)
                printf("%d -> ", count);
            printf("%s", line);
            if (line[strlen(line)-1] != '\n')
                complete = 0;
            else{
                complete = 1;
                count++;
            }
        }

        fclose(fp);
    }

    return EXIT_SUCCESS;
}
