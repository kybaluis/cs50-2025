#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_positive_integer(char c[]);
int coin_optimization(int debt);

int main(void)
{
    char change[100];
    // Ask for change owed; insist until a positive number is provided
    do
    {
        printf("Say, how many cents did I owe you? ");
        scanf("%99s", change);
    }
    while (is_positive_integer(change) == 0);
    printf("%d\n", coin_optimization(atoi(change)));
}

// Decreases debt optimally, prioritizing big coins over lesser ones
int coin_optimization(int debt)
{
    int counter = 0;
    while (debt - 25 >= 0)
    {
        debt -= 25;
        counter++;
    }
    while (debt - 10 >= 0)
    {
        debt -= 10;
        counter++;
    }
    while (debt - 5 >= 0)
    {
        debt -= 5;
        counter++;
    }
    while (debt - 1 >= 0)
    {
        debt--;
        counter++;
    }
    return counter;
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