#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node* next;
}
node;

int main(int argc, char* argv[])
{
    node* list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n -> number = number;
        n -> next = NULL;

        // If list is empty
        if (list == NULL)
        {
            list = n;
        }

        // if element is to be inserted at first position
        else if (n->number < list -> number)
        {
            n -> next = list;
            list = n;
        }

        else
        {
            for (node* tmp = list; tmp != NULL; tmp = tmp -> next)
            {
                // if temp->next == NULL break out so code doesn't access temp->next->number which is outside scope of memory
                if (tmp->next == NULL)
                {
                    tmp->next = n;
                    break;
                }

                // Checking if next number is greater
                // Cannot do it by checking if tmp -> number is greater
                // Because insertion can only occur after tmp, cannot traverse in backward direction
                else if (n->number < tmp->next->number)
                {
                    n->next = tmp->next;
                    tmp->next = n;
                    break;
                }

            }
        }
    }

    // print all numbers in list
    for (node* tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> number);
    }

    // Always free memory
    node* ptr = list;
    while (ptr != NULL)
    {
        node* next = ptr->next;
        free(ptr);
        ptr = next;
    }

}
