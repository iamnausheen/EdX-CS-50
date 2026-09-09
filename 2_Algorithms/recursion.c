#include <cs50.h>
#include <stdio.h>

void draw(int);

int main(void)
{
    int h = get_int("Height: ");
    draw(h);
}

void draw(int height)
{
    if(height <= 0)
    {
        return;
    }

    // drawing a pyramid of height one less than given height
    draw(height - 1);

    //print one more row
    for(int i = 0; i < height; i++)
    {
        printf("#");
    }
    printf("\n");
}
