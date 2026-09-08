#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int number_words(string);
int count_letters(string);
int count_sentences(string);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text : ");

    // Calculate the number of words, letters and sentences in the text
    float words = number_words(text);

    float letters = count_letters(text);

    float sentences = count_sentences(text);

    // Calculate reading index
    float L = (letters / words) * 100;
    float S = (sentences / words) * 100;
    printf("%f %f\n", L, S);

    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int RI = round(index);

    printf("%f %f %f %f\n", words, letters, sentences, index);

    // Print Grade level
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 1 && index < 16)
        printf("Grade %i\n", RI);
    else
        printf("Grade 16+\n");
}

int number_words(string text)
{
    int n = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i] == ' ') && (text[i+1] != ' ' && text[i+1] != '!' && text[i+1] != '?' && text[i+1] != '.'))
            n++;
    }
    return (n + 1);
}

int count_letters(string text)
{
    int n = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
            n++;
    }
    return n;
}

int count_sentences(string text)
{
    int n = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] == '.' || (text[i] == '?' && text[i+1] != '?') || (text[i] == '!' && text[i+1] != '!'))
            n++;
    }
    return n;
}
