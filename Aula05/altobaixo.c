#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Number of Arguments Invalid (Must be 2)\n");
        return EXIT_FAILURE;
    }

    int trys, secret, guess;
    srand(time(NULL));
    secret = atoi(argv[1]) + rand() % (atoi(argv[2]) - atoi(argv[1])+1);
    printf("Guess a number between %s and %s\n", argv[1], argv[2]);
    scanf("%d", &guess);
    trys = 1;

    while (guess != secret)
    {
        if (guess > secret)
            printf("Too High\n");
        else
            printf("Too Low\n");
        scanf("%d", &guess);
        trys++;
    }
    
    printf("You Win! You tried %d times\n", trys);

    return EXIT_SUCCESS;
}

