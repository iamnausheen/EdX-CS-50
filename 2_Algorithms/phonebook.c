#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Algorithm - Linear search

    string names[] = {"Ash", "Brock", "Misty", "Nurse Joy", "Officer Jenny", "Professor Oak"}
    string numbers[] = {"+91-9999999999", "+91-8888888888", "+91-7777777777", "+91-9666666666", "+91-8555555555", "+91-7444444444"}


    string s = get_string("Search: ");

    for (int i = 0; i < 6; i++)
    {
        if(strcmp(names[i], s) == 0)
        {
            printf("Number: %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;   */


    //Algorithm - Binary search
//Not complete
   /* string names[] = {"Ash", "Brock", "Misty", "Nurse Joy", "Officer Jenny", "Professor Oak"}
    string numbers[] = {"+91-9999999999", "+91-8888888888", "+91-7777777777", "+91-9666666666", "+91-8555555555", "+91-7444444444"}

    string s = get_string("Search: ");

    l = 6;

    for(int i = 0; i < 6; i++)
    {
        if(strcmp(names[l/2], s) == 0)
        {
            printf("Number: %s", numbers[l/2]);
            return 0;
        }
        else if(strcmp(names[l], s) > 0)
        {
            printf("Number: %s", numbers[l]);
        }

*/

}
