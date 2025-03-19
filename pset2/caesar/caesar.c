#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void caesar_cipher(int k, char plain[], char cipher[]);

int main(int argc, char *argv[])
{
    // The program won't run unless exactly one non-negative int is provided as argument
    if (argc != 2 || argv[1] < 0 || atoi(argv[1]) == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // The 2nd argument (after the program name) is converted to int and will act as the key
    int k = atoi(argv[1]);
    char plain[50], cipher[50];

    // Takes input from the user up until the carrier return key is entered
    printf("plaintext:  ");
    scanf("%49[^\n]", plain);

    // Calls the cipher function which transforms plaintext -> ciphertext via address pointers
    caesar_cipher(k, plain, cipher);
    printf("ciphertext: %s\n", cipher);
}

void caesar_cipher(int k, char plain[], char cipher[])
{
    // Since the English alphabet only has 26 letters, rotating beyond this number is redundant
    k = k % 26;
    int length = strlen(plain);
    char temp;

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