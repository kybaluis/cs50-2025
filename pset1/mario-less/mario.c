#include <stdio.h>

void construct_pyramid();
int main(void)
{
    int tallness;

    printf("Say, how big do you want the pyramid to be? ");
    scanf("%d", &tallness);
    construct_pyramid(tallness);
}

void construct_pyramid(int height)
{
    /* while(height > 0)
    {
        printf("#  #\n");
        height--;
    }*/
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}