#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    
    if (argc != 4)
    {
        printf("Number of Arguments Invalid (Must be 3)\n");
        return EXIT_FAILURE;
    }
    
    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char op = argv[2][0];

    switch (op)
    {
        case '+':
            printf("%.2f\n", num1 + num2);
            break;
        case '-':
            printf("%.2f\n", num1 - num2);
            break;
        case 'x':
            printf("%.2f\n", num1 * num2);
            break;
        case '/':
            printf("%.2f\n", num1 / num2);
            break;
        case 'p':
            printf("%.2f\n", pow(num1, num2));
            break;
        default:
            printf("Invalid Operator\n");
            break;
    }
    
    return EXIT_SUCCESS;
}
