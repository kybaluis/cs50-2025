#include <stdio.h>

int main(void)
{
    char word1[50];
    char word2[50];

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