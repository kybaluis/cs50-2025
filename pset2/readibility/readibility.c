#include <stdio.h>

int count_letters(char text[]);
int count_words(char text[]);
int count_sentences(char text[]);

int main(void)
{
    char text[500];

    printf("Enter the text to be evaluated: ");
    scanf("499%s", text);

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float l = 100 * letters / words;
    float s = 100 * sentences / words;

    float index = 0.0588 * l - 0.296 * s - 15.8;

    printf("%f\n", index);
}

int count_letters(char text[])
{
    return 80;
}

int count_words(char text[])
{
    return 21;
}

int count_sentences(char text[])
{
    return 3;
}