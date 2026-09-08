#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node* next;
}node;

int main(int argc, char* argv[])
{
    node* list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Free any existing allocated memory
            return 1;
        }

        // Pre-pending a linked list = O(1)
        n -> number = number; // number in n -> number is the number field of the node struct, number on the right of assignment is the number from CLI argument
        n -> next = list;
        list = n;
    }

    // Appending a linked list = O(n)

    node* n = malloc(sizeof(node));
    n -> number = 4;
    n -> next = NULL;

    if (list == NULL)
    {
        list = n;
    }
    else
    {
        for (node* tmp = list; tmp != NULL; tmp = tmp -> next)
        {
            if (tmp -> next == NULL)
            {
                tmp -> next = n;
                break;
            }
        }
    }


    node* ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    ptr = list;
    node* next = NULL;
    while(ptr != NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(next);

}
