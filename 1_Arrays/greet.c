#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    printf("Hello, ");
    for (int i = 1; i < argc; i++)
    {
        for(int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            printf("%c", toupper(argv[i][j]));
        }
        if (i == argc - 1)
        printf("!");
        else
        printf(" ");
    }
    printf("\n");
}
