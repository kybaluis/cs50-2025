#include <stdio.h>
#include <string.h>
#include <ctype.h>

int scrabble_scoring(char word[]);

int main(void)
{
    char word1[50], word2[50];

    printf("Enter Player #1's word: ");
    scanf("%49s", word1);
    printf("Enter Player #2's word: ");
    scanf("%49s", word2);

    int score1 = scrabble_scoring(word1);
    int score2 = scrabble_scoring(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// Takes a word as input and calculates the scrabble score
int scrabble_scoring(char word[])
{
    int score = 0;
    int word_length = strlen(word);
    // Iterates over each character in the word
    for (int i = 0; i < word_length; i++)
    {
        // For simplicity, all words are treated as lower case
        word[i] = tolower(word[i]);

        // Common letters have less value in Scrabble
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i'
            || word[i] == 'l' || word[i] == 'n' || word[i] == 'o' 
            || word[i] == 'r' || word[i] == 's' || word[i] == 't' || word[i] == 'u')
        {
            score += 1;
        }
        else if (word[i] == 'd' || word[i] == 'g')
        {
            score += 2;
        }
        else if (word[i] == 'b' || word[i] == 'c' || word[i] == 'm' || word[i] == 'p')
        {
            score += 3;
        }
        else if (word[i] == 'f' || word[i] == 'h' || word[i] == 'v' || word[i] == 'w' || word[i] == 'y')
        {
            score += 4;
        }
        else if (word[i] == 'k')
        {
            score += 5;
        }
        else if (word[i] == 'j' || word[i] == 'x')
        {
            score += 8;
        }
        else if (word[i] == 'q' || word[i] == 'z')
        {
            score += 10;
        }
    }
    return score;
}