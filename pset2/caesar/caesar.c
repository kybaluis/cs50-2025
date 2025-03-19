#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void caesar_cipher(int k, char plain[], char cipher[]);

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1] < 0 || atoi(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int k = atoi(argv[1]);
    char plain[50];
    char cipher[50];

    printf("plaintext:  ");
    scanf("%49[^\n]", plain);
    caesar_cipher(k, plain, cipher);
    printf("ciphertext: %s\n", cipher);
}

void caesar_cipher(int k, char plain[], char cipher[])
{
    // printf("%d", k);
    k = k % 26;
    // printf("%d", k);
    char temp;
    int length = strlen(plain);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(plain[i]))
        {
            if (plain[i] + k > 122)
            {
                temp = plain[i] + k - 26;
            }
            else
            {
                temp = plain[i] + k;
            }
        }
        else
        {
            temp = plain[i];
        }
        cipher[i] = temp;
    }
    cipher[length] = '\0';
}