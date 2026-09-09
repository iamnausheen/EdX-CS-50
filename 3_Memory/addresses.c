#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main (void)
{
    // Printing value of n
    int n = 50;
    printf("%i\n", n);

    // Printing address of n in memory
    printf("%p\n", &n);


    // GOING TO A MEMORY LOCATION AND CHECKING WHAT'S INSIDE
    // Declaring a pointer(a variable storing the memory location of another variable)
    int* p = &n;        // * is used in the context of declaration, int* is the data type used to store memory addresses
    printf("%i\n", *p);  // * is used as an operator which goes to the stored memory location

    // We don't really care about the actual value of the memory address, therefore it is more functional to think about the int* data type as an arrow
    // pointing to the memory location as compared to the value of the memory address by itself.


    // STRINGS
 /*   string s = "HI!";
    printf("%s\n", s);

    printf("%p\n", s);

    for (int i = 0; i <= strlen(s); i++)
    {
        printf("%p\n", &s[i]);
    }

*/
    // A string is essentially the memory address of it's first character
    // Without the cs50 library

    char* s = "HI!";
    printf("%s\n", s);  // %s refers to char*, %s prints values char* is pointing to until null value is encountered
    printf("%p\n", s);  // "" do the work of &, therefore s = &"HI!" isn't required.

    // Printing a string
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);

    // What compiler does with the array notation
    printf("%c", *s);
    printf("%c", *(s+1));
    printf("%c\n", *(s+2));
}


/*
What exactly is a string in c

ddb
In C programming, a string is a sequence of characters terminated with a null character '\0'.
It's essentially an array of characters.
For example, the string "hello" is represented as 'h', 'e', 'l', 'l', 'o', '\0' in an array.
The '\0' is important as it signals the end of the string.

you
If a string s is an array then how does it store the memory address of the first character,
it can either be an array of char or a pointer so what exactly is it

ddb
In C, a string is typically represented as a pointer to the first character of the string.
When you declare a string like char&nbsp;s[]&nbsp;=&nbsp;"hello";,
the variable s is essentially a pointer to the first character of the string.
The string itself is stored in an array of characters in memory, and s holds the memory address of the first character.
So, in a way, a string in C is both an array and a pointer.
It's an array in the sense that it's a sequence of characters stored in contiguous memory locations,
and it's a pointer in the sense that the string variable holds the memory address of the first character.

you
So is it like s[0] holds it's own memory address or does it hold the first char of the string

ddb
In C, s[0] would hold the first character of the string, not its own memory address.
If s is a string, s itself holds the memory address of the first character,
and s[0] is the way to access the first character stored at that memory address.

you
How can one particular data type be a pointer and an array of char

ddb
In C, an array name is essentially a constant pointer to the first element of the array.
So when you declare an array of characters (a string), the array name is a pointer to the first character.
However, there are some differences between pointers and arrays that you should be aware of.
For example, you can increment a pointer, but you cannot increment an array name because it's a constant pointer.

you
So is being a constant pointer a property of all arrays and not just strings

ddb
Yes, that's correct.
The name of any array in C, not just an array of characters (i.e., a string),
is essentially a constant pointer to the first element of the array. This is a fundamental aspect of how arrays work in C.
*/
