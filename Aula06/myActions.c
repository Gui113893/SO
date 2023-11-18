#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man system
 man date
*/

int main(int argc, char *argv[])
{
    char text[1024];
    FILE *fp = NULL;
    FILE *datePipe;
    char date[64];

    fp = fopen("command.log", "a+");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    do
    {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        /* system(const char *command) executes a command specified in command
            by calling /bin/sh -c command, and returns after the command has been
            completed.
        */
        if(strcmp(text, "end")) {
            datePipe = popen("date +'%Y-%m-%d %H:%M:%S'", "r");
            fgets(date, sizeof(date), datePipe);
            pclose(datePipe);

            fprintf(fp, "%-50s | %s", text, date);
            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);
            printf("---------------------------------\n");
        }
    } while(strcmp(text, "end"));

    printf("-----------The End---------------\n");

    return EXIT_SUCCESS;
}
