#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What's your name? ");
//without using ctype.h
    //for (int i = 0, n = strlen(name); i < n; i++)
    //{
        //if (name[i] > 'a' || name[i] < 'z')
            //printf("%c",name[i] - ('a' - 'A'));
        //else
            //printf("%c",name[i]);
    //}
    //printf("\n");

    //with ctype.h
    for(int i = 0, n = strlen(name); i < n; i++)
    {
        printf("%c", toupper(name[i]));
    }
    printf("\n");

}

