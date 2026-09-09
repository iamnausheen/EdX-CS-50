#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /*
    string s = get_string("Word: ");

    string t = s;       // t is a string -> t is a pointer -> t points to memory location of first char of s

    if (strlen(s) > 0)
            t[1] = toupper(t[1]);

    printf("%s\n", s);
    printf("%s\n", t);
    */

   char* s = get_string("Word: ");

   if (s == NULL)
   {
        return 1;
   }

   char* t = malloc(strlen(s) + 1);

   if (t == NULL)
   {
        return 1;
   }

   strcpy(t, s);


   t[0] = toupper(t[0]);

   printf("%s\n", s);
   printf("%s\n", t);

   // freeing memory assigned by malloc
   // get_string handles memory by itself, do not free memory allocated through get_ function
   free(t);

   return 0;
}
