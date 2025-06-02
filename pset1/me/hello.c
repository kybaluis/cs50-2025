#include <stdio.h>

/*
 * me.c
 * CS50 2025 pset 1.1
 * -------------------------------------------
 * Simply prompts the user for their name and prints a personalized greeting.
 */

int main(void)
{
    char name[50];

    //Captures and prints the captured name
    printf("What's your first name? ");
    scanf("%49s", name);
    printf("Hello, %s\n", name);
}
