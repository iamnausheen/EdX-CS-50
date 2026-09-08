#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_score(string, int);
string uppercase(string, int);

int main(void)
{
    // Prompt players for words
    string word1 = get_string("Player 1 : ");
    string word2 = get_string("Player 2 : ");

    // check length of each word
    int length1 = strlen(word1);
    int length2 = strlen(word2);

     // convert both to uppercase
    string word1_up = uppercase(word1, length1);
    string word2_up = uppercase(word2, length2);

    // check each player's score
    int score1 = check_score(word1_up, length1);
    int score2 = check_score(word2_up, length2);

    // compare scores and declare winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if ( score2 > score1)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}

int check_score(string word, int length)
{
    int score = 0;
    for ( int i = 0; i < length; i++)
    {
        if (word[i] == 'A' || word[i] == 'E' || word[i] == 'J' || word[i] == 'L' || word[i] == 'N' || word[i] == 'O' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T' || word[i] == 'U')
            score += 1;
        else if (word[i] == 'D' || word[i] == 'G')
            score += 2;
        else if (word[i] == 'B' || word[i] == 'C' || word[i] == 'M' || word[i] == 'P')
            score += 3;
        else if (word[i] == 'F' || word[i] == 'H' || word[i] == 'Y' || word[i] == 'V' || word[i] == 'W')
            score += 4;
        else if (word[i] == 'K')
            score += 5;
        else if (word[i] == 'J' || word[i] == 'X')
            score += 8;
        else if (word[i] == 'Q' || word[i] == 'Z')
            score += 10;
        else
            score += 0;
}
    return score;
}

string uppercase(string word_before, int length)
{
    char word_after[length];
    for(int i = 0; i < length; i++)
    {
        if (islower(word_before[i]))
        {
            word_after[i] = toupper(word_before[i]);
        }
        return word_after;
    }
}
