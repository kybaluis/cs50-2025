#include <stdio.h>

int main(void)
{
    int tallness;

    printf("Say, how big do you want the pyramid to be? ");
    scanf("%d", &tallness);
    printf("I'll do my best to print this %d-story pyramid\n", tallness);
}

