#include <cs50.h>
#include <stdio.h>

int get_change(void);

int main(void)
{
    // Prompt user for change
    int c = get_change();

    // Calculate minimum number of coins
    int quarters = c / 25;
    int dimes = (c % 25) / 10;
    int nickels = ((c % 25) % 10) / 5;
    int pennies = ((c % 25) % 10) % 5;
    int total = quarters + dimes + nickels + pennies;

    // Print total coins
    printf("%i\n", total);
}

int get_change(void)
{
    int x;
    do
    {
        x = get_int("Change owed :  ");
    }
    while (x < 0);
    return x;
}


