#include <stdio.h>
#include <cs50.h>

int main(void)
{
    FILE* file = fopen("phonebook.csv", "a");

    if (file == NULL)               // If anything goes wrong with pointers or the malloc function NULL value is returned
        return 1;

    char* name = get_string("Name: ");
    char* number = get_string("Number: ");

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);

    return 0;
}
