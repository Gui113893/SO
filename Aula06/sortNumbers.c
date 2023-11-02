#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/

int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i, numSize;
    int *numbers;
    FILE *fp = NULL;
    char line [80];

    /* Validate number of arguments */
    if( argc != 2 )
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file provided as argument */
    printf("\nOpening file %s\n", argv[1]);
    errno = 0;
    fp = fopen(argv[1], "r");
    if( fp == NULL )
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }


    numSize=0;
    i = 0;
    while( fgets(line, sizeof(line), fp) != NULL )
    {
        if (numSize == 0){
            /* Memory allocation for all the numbers in the arguments */
            /* The first argument is the number of numbers */
            numbers = (int *) malloc(sizeof(int) * atoi(line));
            numSize = atoi(line);
        }else{
            numbers[i] = atoi(line);   
            i++; 
        }    
    }
    fclose(fp);
    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numSize, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numSize ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}
