#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_row(int, int);

int main(void)
{
    // Prompt user for height
    int h = get_height();

    int i;
    for (i = 0; i < h; i++)
    {
        print_row(i, h);
        printf("\n");
    }
}

// get_height function
int get_height(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (1 > h || h > 8);
    return h;
}

// print_row function
void print_row(int row, int height)
{
    for (int j = height - 1; j > row; j--)
        printf(" ");
    for (int k = 0; k < row + 1; k++)
        printf("#");
    printf("  ");
    for (int l = 0; l < row + 1; l++)
        printf("#");
}
