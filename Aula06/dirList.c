#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[])
{
    DIR *dp; 
    struct dirent *dent;

    dp = opendir(dirname); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while(dent!=NULL) 
    {
        if(dent->d_name[0] != '.') /* do not list hidden dirs/files */
        {
            char name[100] = "";
            printf("%s/",dirname);
            if (dent->d_type == DT_DIR){
                printf("d %s\n", dent->d_name);
                strcat(name, dirname);
                strcat(name, "/");
                strcat(name, dent->d_name);
                listDir(name);
            }
            else
                printf("  %s\n", dent->d_name);
        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}

