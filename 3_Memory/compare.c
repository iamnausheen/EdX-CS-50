#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Comparing two numbers
    int n = get_int("Number: ");
    int m = get_int("Number: ");

    if (n == m)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

    // Comparing two strings
    string s = get_string("Word: ");
    string t = get_string("Word: ");

    if (s == t)         // Compares memory addresses, different everytime
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
    printf("%p\n", s);
    printf("%p\n", t);


    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}
