#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ciphertext(string);
int only_digits(string);

char ALPHABETS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char alphabets[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int key;

int main(int argc, string argv[])
{
    int x = only_digits(argv[1]);

    // Printing error messages when arguements are invalid
    if ((argc != 2) || only_digits(argv[1]) == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Converting string to int
    key = atoi(argv[1]);

    // Prompting user for input
    string plaintext = get_string("plaintext : ");

    // Converting plaintext to ciphertext
    ciphertext(plaintext);
    printf("\n");
}

void ciphertext(string plaintext)
{
    printf("ciphertext: ");
    int cipher;
    int j;
    int i;
    int n = strlen(plaintext);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 26; j++)
        {
            if (plaintext[i] == alphabets[j] || plaintext[i] == ALPHABETS[j])
            {
                cipher = (j + key) % 26;

                if (islower(plaintext[i]))
                    printf("%c", alphabets[cipher]);

                else if (isupper(plaintext[i]))
                    printf("%c", ALPHABETS[cipher]);
            }
        }
        if (!(isalpha(plaintext[i])))
            printf("%c", plaintext[i]);
    }
}

int only_digits(string x)
{
    int m;
    for (int i = 0, n = strlen(x); i < n; i++)
    {
        if (x[i] >= 48 && x[i] <= 57)
            m = 0;

        else
            m = 1;
    }
    return m;
}
