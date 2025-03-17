#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int coleman_liau(int letters, int words, int sentences);
int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[500];

    // Reads all user input everything until a newline is encountered
    printf("Enter the text to be evaluated: ");
    scanf("%499[^\n]", text);

    // Call three different functions to count letters, words, and sentences respectively
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = coleman_liau(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

int coleman_liau(int letters, int words, int sentences)
{
    // Calculates average of letters and sentences per 100 words each
    float l = (float) 100 * letters / words;
    float s = (float) 100 * sentences / words;

    // Returns the Coleman-Liau index after applying the formula
    return round(0.0588 * l - 0.296 * s - 15.8);
}

int count_letters(char text[])
{
    int counter = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        // For simplicity, all words are treated as lower case
        text[i] = tolower(text[i]);
        if (isalnum(text[i]))
        {
            counter++;
        }
    }
   //printf("%d", counter);
    return counter;
}

int count_words(char text[])
{
    int counter = 1;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (isblank(text[i]))
        {
            counter++;
        }
    }
    //printf("%d", counter);
    return counter;
}

int count_sentences(char text[])
{
    int counter = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            counter++;
        }
    }
    //printf("%d", counter);
    return counter;
}