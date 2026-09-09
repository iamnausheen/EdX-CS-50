#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Remove comments from one chunk of code at a time and run 

    // Searching for an integer from an array
    /* int Numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Search for: ");

    for (int i = 0; i < 7; i++)
    {
        if (Numbers[i] == n)
        {
            printf("Found\n");
            return 0;           //Once a value is returned from main, the program exits, doesn't perform any further steps
        }
    }
    printf("Not found\n");
    return 1;   */

    // Searching for a string in an array
    /* string strings[] ={"Green", "Blue", "Red", "Orange", "Purple", "Pink", "Yellow"};

    string str = get_string("Search for: ");

    for(int i = 0; i < 6; i++)
    {
        if(strcmp(strings[i],str) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;   */


    //strcmp function
   /* The strcmp function compares two strings character by character.
    It starts at the beginning of each string and continues until it finds characters that aren't the same or until
    it reaches the end of one of the strings.
    The function uses the ASCII values of the characters to make the comparison. If the ASCII value of the character
    in the first string is less than the character in the same position in the second string, strcmp returns a negative number.
    If the ASCII value is greater, it returns a positive number. If all the characters are the same in both strings,
    strcmp returns 0, indicating the strings are equal.

    printf("%i\n", strcmp("Hello","Gello"));

    Output = 1

    printf("%i", strcmp("Hellp","Gello"));

    Output = 1 */




}

