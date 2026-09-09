#include <stdio.h>

int main(void)
{

    int scores[1024];

    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]);
    }

    int* y;     // The variables haven't been told where exactly to point to, pointing at some garbage value
    int* z;     // That garbage value can be inaccessable and lead to crashes

    y = malloc(sizeof(int));       // y points to this particular allocated memory
                                   // malloc returns the memory address of the first container of memory allocated

    *y = 100;

    // *z = *y  -> shouldn't be done, we are not exactly sure where y is pointing to, if that memory is even accessible


     z = y                          // z points the memory address stored in y
    *z = 50;                        // value at memory address stored in y changed to 50 from 100

    free(y);


}
