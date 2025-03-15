#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void build_pyramid(int height);
int is_positive_integer(char c[]);

int main(void)
{
    char height[100];
    // Ask for pyramid height; insist until a positive number is provided
    do
    {
        printf("Say, how many levels do you want the pyramid to be? ");
        scanf("%99s", height);
    }
    while (is_positive_integer(height) == 0);

    build_pyramid(atoi(height));
}

void build_pyramid(int n)
{
    // Pyramids are built in a kind of grid with i-rows and j-columns
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // The higher the pyramid, the more padding is needed in the first rows & columns  
            if (i + j <= n)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Checks whether the string corresponds to an actual positive and valid integer
int is_positive_integer(char c[])
{
    for (int i = 0, length = strlen(c); i < length; i++)
    {
        if (isdigit(c[i]) == 0 || atoi(c) == 0)
        {
            return 0;
        }
    }
    return 1;
}