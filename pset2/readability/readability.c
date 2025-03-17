#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[500];

    // Reads all user input everything until a newline is encountered
    printf("Enter the text to be evaluated: ");
    scanf("%499[^\n]", text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = 100 * letters / words;
    float s = 100 * sentences / words;

    int index = round(0.0588 * l - 0.296 * s - 15.8);

    printf("Grade %d\n", index);
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