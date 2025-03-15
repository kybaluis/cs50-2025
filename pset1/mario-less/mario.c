#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void build_pyramid(int height);
int is_positive_integer(char c[]);

int main(void)
{
    char tallness[100];
    do
    {
        printf("Say, how big do you want the pyramid to be? ");
        scanf("%99s", tallness);
    }
    while(is_positive_integer(tallness) == 0 || atoi(tallness) == 0);

    build_pyramid(atoi(tallness));
}

void build_pyramid(int height)
{
    // i = row_number and j = column_number
    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j >= i; j--)
        {
            //Checks whether white-space padding is needed
            if (j > i)
            {
                printf(" ");
            }
            else
            {
                int current_row = i;
                while (current_row > 0)
                {
                    printf("#");
                    current_row--;
                }
            }
        }
        printf("\n");
    }
}

int is_positive_integer(char c[])
{
    for (int i=0, length=strlen(c); i<length; i++)
    {
        if (isdigit(c[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}