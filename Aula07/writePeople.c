#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct
{
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p)
{
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main (int argc, char *argv[])
{
    FILE *fp = NULL;
    int i, nPeople;
    Person p;

    /* Validate number of arguments */
    if(argc != 2)
    {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Enter the number of people: ");
    scanf("%d", &nPeople);

    /* Open the file provided as argument */
    errno = 0;
    fp = fopen(argv[1], "wb");
    if(fp == NULL)
    {
        perror ("Error opening file!");
        return EXIT_FAILURE;
    }

    /* Write nPeople itens on a file */
    for(i = 0 ; i < nPeople ; i++)
    {    
        printf("Enter the name of the person: ");
        scanf("%ls", &p.name);
        printf("Enter the age of the person: ");
        scanf("%d", &p.age);
        printf("Enter the height of the person: ");
        scanf("%lf", &p.height);
        
        fwrite(&p, sizeof(Person), 1, fp);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}
