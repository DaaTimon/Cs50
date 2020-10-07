// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//initializing wordcount to fix undeclared issue
int wordcount = 0;

// Number of buckets in hash table
const unsigned int N = 17576;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int wordposition = hash(word);
    node *cursor = table[wordposition];

    while (cursor != NULL)
    {
        if ((strcasecmp(cursor->word, word)) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int index = 0 ;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        index += tolower(word[i]) ;
    }
    return index % N ;
}

//diego(2020) hash function (1.0) [Source Code]. stack overflow

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open Dictonary
    FILE *file = fopen(dictionary, "r");
    int count = 0;
    char word[LENGTH + 1];
    node *head = NULL;

    if (file == NULL)
    {
        return false;
    }

    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        strcpy(n->word, word);
        int index = hash(word);
        wordcount++;

        if (n == NULL)
        {
            return false;
        }

        if (table[index] == NULL)
        {
            n->next = NULL;
            table[index] = n;
            head = n;
        }
        else
        {
            head = n;
            n->next = table[index];
            table[index] = n;
        }

        count ++;
    }
    fclose(file);
    return true;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {

        node *cursor = table[i];

        while (cursor)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}