#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void cipher_text(string);
void store_by_case(string, string, string);
int check_repetition(string, char);

char key_up[26];
char key_low[26];

int main(int argc, string argv[])
{
    // Print error in case of invalid key
    for (int i = 'a'; i <= 'z'; i++)
    {

        if (argc != 2 || strlen(argv[1]) != 26 || check_repetition(argv[1], i) != 1)
        {
            printf("ERROR CODE 1 : INVALID KEY\n");
            return 1;
        }
    }

    // Store key in arrays according to case

    // key_up contains key in upper case letters
    store_by_case(argv[1], "upper", key_up);
    // key_low contains key in lower case letters
    store_by_case(argv[1], "lower", key_low);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    // Convert plaintext to ciphertext and print
    printf("ciphertext: ");
    cipher_text(plaintext);
    printf("\n");

    // return value on successful execution
    return 0;
}

// Function to convert alphabets to ciphertext
void cipher_text(string plaintext)
{
    int i;
    int j;
    int k;
    int l = strlen(plaintext);
    for (i = 0; i < l; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i]))
            {
                for (j = 'A'; j <= 'Z'; j++)
                {
                    if (plaintext[i] == j)
                    {
                        printf("%c", key_up[j - 'A']);
                    }
                }
            }

            else if (islower(plaintext[i]))
            {
                for (k = 'a'; k <= 'z'; k++)
                {
                    if (plaintext[i] == k)
                    {
                        printf("%c", key_low[k - 'a']);
                        break;
                    }
                }
            }
        }

        else if (!(isalpha(plaintext[i])))
            printf("%c", plaintext[i]);
    }
}

// Storing key in a uppercase and a lower case
void store_by_case(string key, string CASE, string array)
{
    for (int i = 0; i < 26; i++)
    {
        // Storing in uppercase
        if (strcmp(CASE, "upper") == 0)
        {
            if (isupper(key[i]))
                array[i] = key[i];
            else
                array[i] = toupper(key[i]);
        }
        else if (strcmp(CASE, "lower") == 0)
        {
            if (islower(key[i]))
                array[i] = key[i];
            else
                array[i] = tolower(key[i]);
        }
    }
}

int check_repetition(string key, char a)
{
    int k = 0;
    for (int i = 0; i < 26; i++)
    {
        {
            if (tolower(key[i]) == tolower(a) || toupper(key[i]) == toupper(a))
                k++;
        }
    }
    return k;
}
