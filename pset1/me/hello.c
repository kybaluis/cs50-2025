#include <stdio.h>

int main(void)
{
    char name[50];

    //Captures and prints the captured name
    printf("What's your first name? ");
    scanf("%49s", name);
    printf("Hello, %s\n", name);
}