#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void caesar_cipher(int k, char plain[], char cipher[]);

int main(int argc, char *argv[])
{
    int k = atoi(argv[1]);
    char plain[50];
    char cipher[50];

    printf("plaintext:  ");
    scanf("%49s", plain);
    caesar_cipher(k, plain, cipher);
    printf("ciphertext: %s\n", cipher);
}

void caesar_cipher(int k, char plain[], char cipher[])
{
    char temp;
    int length = strlen(plain);
    for (int i = 0; i < length; i++)
    {
        temp = plain[i] + k;
        cipher[i] = temp;
    }
    cipher[length] = '\0';
}