#include <stdio.h>

void build_pyramid();
int main(void)
{
    int tallness;
    do
    {
        printf("Say, how big do you want the pyramid to be? ");
        scanf("%d", &tallness);
    }
    while(tallness < 0 || tallness > 8);
    
    build_pyramid(tallness);
}

void build_pyramid(int height)
{
    // i = row_number and j = column_number
    for (int i = 1; i <= height; i++)
    {
        for (int j = height; j >= i; j--)
        {
            if(j > i)
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