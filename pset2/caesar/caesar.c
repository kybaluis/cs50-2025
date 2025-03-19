#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void caesar_cipher(int k, char plain[], char cipher[]);

int main(int argc, char *argv[])
{
    // The program won't run if either of the following oddities take place
    if (argc != 2 || atoi(argv[1]) <= 0 || argv[1] == NULL || strcmp(argv[1], "\0") == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // The 2nd argument  is converted to int and will act as the key
    int k = atoi(argv[1]);
    char plain[50], cipher[50];

    // Takes input from the user up until the carrier return key is entered
    printf("plaintext:  ");
    scanf("%49[^\n]", plain);

    // Calls the cipher function which transforms plaintext -> ciphertext via address pointers
    caesar_cipher(k, plain, cipher);
    printf("ciphertext: %s\n", cipher);
    return 0;
}

void caesar_cipher(int k, char plain[], char cipher[])
{
    // Since the English alphabet only has 26 letters, rotating beyond this number is redundant
    k = k % 26;
    int length = strlen(plain);

    for (int i = 0; i < length; i++)
    {
        // If a character is not an actual letter but, say, a bang (!) is left unmodified
        while (!isalpha(plain[i]))
        {
            cipher[i] = plain[i];
            i++;
        }

        // When letter + key surpasses this number, an overflow has happened and wrapping is needed
        if (plain[i] + k > 122)
        {
            cipher[i] = plain[i] + k - 26;
        }
        
        // If nothing extraordinary happens, a simple letter + key rotation takes place 
        else
        {
            cipher[i] = plain[i] + k;
        }
    }
    cipher[length] = '\0';
}