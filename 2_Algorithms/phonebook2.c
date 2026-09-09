#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
} entry;

int main(void)
{
    string name = get_string("Search for: ");

    entry entries[4];

     entries[0].name = "Ash";
     entries[0].number = "+91-9999999999";

     entries[1].name = "Brock";
     entries[1].number = "+91-8888888888";

     entries[2].name = "Misty";
     entries[2].number = "+91-7777777777";

     entries[3].name = "Nurse Joy";
     entries[3].number = "+91-9666666666";

     for (int i = 0; i < 4; i++)
    {
        if(strcmp(entries[i].name,name) == 0)
        {
            printf("Number: %s\n", entries[i].number);
            return 0;
        }
    }
        printf("Not found\n");
        return 1;

}
