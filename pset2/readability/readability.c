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

    // Rea all user input until a newline is encountered
    printf("Enter the text to be evaluated: ");
    scanf("%499[^\n]", text);

    // Call three different functions to count letters, words, and sentences respectively
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Call the function that calculates the actual Coleman-Liau index
    int index = coleman_liau(letters, words, sentences);

    // Depending on the index, the grade is determined
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
        // When either a letter or number is found, a new letter is assumed
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
    int counter = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        // The first blank space implies not one but two words
        if (isblank(text[i]) && counter == 0)
        {
            counter += 2;
        }
        // Now blank spaces simply imply one additional word
        else if (isblank(text[i]) && counter != 0)
        {
            counter++;
        }
    }
    return counter;
}

int count_sentences(char text[])
{
    int counter = 0;
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++)
    {
        // When either of these three symbols is found, a new sentence is assumed
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            counter++;
        }
    }
    return counter;
}