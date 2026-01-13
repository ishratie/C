#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // promt the user for some text

    string text = get_string("Text: ");

    // count the number of letters, words, and sentences in the text

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / words) * 100;

    float S = ((float) sentences / words) * 100;

    // compute the coleman liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // print the grade level

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}

int count_letters(string text)
{
    // return the number of letters in the text

    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    // return the number of words in the text

    int count = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    // return the number of sentences in text

    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count++;
        }
    }
    return count;
}
