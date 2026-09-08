#include <cs50.h>
#include <stdio.h>

// Global variable
const int N = 3;
int main(void)
{
    int scores[3];
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
        sum = scores[i] + sum;
    }
    printf("Average = %f\n", sum/N);
}
