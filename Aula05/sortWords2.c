#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int strcasecmp(const char *a, const char *b) {
    for (; *a && *b; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0) return d;
    }
    return *a - *b;
}

int compare_n(const void *a, const void *b){
    return strcasecmp(*(char **)a, *(char **)b);
}

int compare_r(const void *a, const void *b){
    return strcasecmp(*(char **)b, *(char **)a);
}



int main(int argc, char **argv)
{
    char *sort;
    char *str[100];
    int n = 0;
    

    //export SORTORDER="r" or "n"
    sort = getenv("SORTORDER");
    if(sort == NULL)
    {
        printf("ERROR: SORTORDER not defined\n");
        return EXIT_FAILURE;
    }

    //Ask the user for words, if the user enters a number, stop asking

    char word[100];
    printf("Enter a word(number to end): ");
    scanf("%s", word);
    while (isalpha(word[0]))
    {
        str[n] = malloc(strlen(word) + 1);
        strcpy(str[n], word);
        n++;
        printf("Enter a word(number to end): ");
        scanf("%s", word);
    }

    if (strcmp(sort, "r") == 0)
    {
        qsort(str, n, sizeof(char*), compare_r);
    }
    else if (strcmp(sort, "n") == 0)
    {
        qsort(str, n, sizeof(char*), compare_n);
 
    }
    else
    {
        printf("ERROR: SORTORDER must be 'r' or 'n'\n");
        return EXIT_FAILURE;
    }

    printf("Sorted words:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", str[i]);
    }

    return EXIT_SUCCESS;
}

