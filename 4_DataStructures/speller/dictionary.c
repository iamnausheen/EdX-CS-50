// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// global variables
unsigned int count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word
    int hash_value = hash(word);
    // Go to place in hash table
    // Iterate over list at that place untill word is found
    node* ptr = table[hash_value]->next;
    while(ptr != NULL)
    {
        if (strcasecmp(word, ptr->word) == 0)
        {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Couldn't open dictionary\n");
        return false;
    }

    // read a word
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        count++;

        // When word read, find a place for it in hash table
        unsigned int hash_value = hash(word);


        // Write word in hash table

        // Insert new node
        node* n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Not enough Memory\n");
            return false;
        }
        strcpy(n -> word, word);
        if (table[hash_value] == NULL)
        {
            table[hash_value] = n;
        }
        else
        {
            n -> next = table[hash_value] -> next;
            table[hash_value] -> next = n;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node* tmp = table[i]->next;
        while(tmp != NULL)
        {
            table[i] = tmp;
            free(table[i]);
            tmp = tmp->next;
        }
    }
    return true;
}
