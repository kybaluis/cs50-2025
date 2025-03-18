#include <stdio.h>
#include <string.h>

void caesar_cipher(int k, char plain[], char cipher[]);

int main(void)
{
    int k = 0;
    char plain[50];
    char cipher[50];

    printf("Key: ");
    scanf("%d", &k);
    printf("Plain text:  ");
    scanf("%49s", plain);
    caesar_cipher(k, plain, cipher);
    printf("%s\n", cipher);
}

void caesar_cipher(int k, char plain[], char cipher[])
{
    char temp;
    int length = strlen(plain);
    for (int i = 0; i < length; i++)
    {
        temp = plain[i];
        cipher[i] = temp + k;
    }
    cipher[length] = '\0';
}