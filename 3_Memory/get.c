#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // getting an int
    int n;                  // Standard 4 bytes of memory allocated
    printf("n: ");
    scanf("%i", &n);        // Allocated memory values overwritten with user input
    printf("n: %i\n", n);

    // getting  a string
/*
    char* s;                            // segmentation fault - trying to access memory that shouldn't be touched
    printf("s: ");           // Standard 8 bytes allocated for a string or char*, couldn't be overwritten since
    scanf("%s", s);         // char* s is an unitialized pointer, it doesn't know what location to overwrite
    printf("s: %s", s);
*/

    char*s = malloc(4);     // Only allocates memory for 3 letters and a null character
    if (s == NULL)
        return 1;
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);

    // More simply
    char s[4];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s", s);


}
