#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    printf("Allocating 3 memory for 3 ints\n");
    const int C = 3;
    int* list = malloc(3*sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    //can use array notation for pointer arithemetic

    for (int i = 0; i < C; i++)
    {
        list[i] = i+1;
    }

    printf("..............................................\n");

    printf("Allocating more memory for a bigger list\n");

    int* tmp = malloc(4*sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    printf("Copying previous list ....\n Adding new element into new list\n");

    for (int i = 0; i < C; i++)
    {
        tmp[i] = list[i];
    }
    tmp[C] = 4;

    free(list);
    list = tmp;

     for (int i = 0; i < C+1; i++)
    {
        printf("%i\n", list[i]);
    }


    free(list);
    return 0;
}
