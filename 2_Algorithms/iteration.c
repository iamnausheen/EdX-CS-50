#include <cs50.h>
#include <stdio.h>

void draw(int );

int main(void)
{
    int h = get_int("Height: ");
    draw(h);
}

void draw(int height)
{
    for (int i = height - 1; i >= 0; i--)
    {
        for (int j = i; j < height; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
