#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int calculate_score(string word, int length);

// Declaring global variable
int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    // Prompt players for words
    string word1 = get_string("Player 1 : ");
    string word2 = get_string("Player 2 : ");

    // Find length of each word
    int length1 = strlen(word1);
    int length2 = strlen(word2);

    // Calculate scores of each player
    int score1 = calculate_score(word1, length1);
    int score2 = calculate_score(word2, length2);

    // Compare scores and declare winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int calculate_score(string word, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        // if (word[i] >= 'A' && word[i] <= 'Z')
        if (isupper(word[i]))
            sum += scores[word[i] - 65];
        // else if (word[i] >= 'a' && word[i] <= 'z')
        else if (islower(word[i]))
            sum += scores[word[i] - 97];
    }
    return sum;
}
