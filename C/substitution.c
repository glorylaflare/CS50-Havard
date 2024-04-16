#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool validate_key(string key);
void substitution(string key);
char transform_char(char c, string key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution KEY");
        return 1;
    }

    if(!validate_key(argv[1]))
    {
        return 1;
    }

    substitution(argv[1]);

    printf("\n");
}

bool validate_key(string key)
{
    int key_length = strlen(key);
    if(key_length != 26)
    {
        printf("Key must contain 26 characteres.");
        return false;
    }

    for(int i = 0; i < key_length; i++)
    {
        if(!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.");
            return false;
        }

        for(int y = i + 1; y < key_length; y++)
        {
            if(key[i] == key[y])
            {
                printf("Key must not contain repeated characters.");
                return false;
            }
        }
    }

    return true;
}

void substitution(string key)
{
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i = 0; i < strlen(plaintext); i++)
    {
        printf("%c", transform_char(plaintext[i], key));
    }
    printf("\n");
}

char transform_char(char c, string key)
{
    if(isupper(c))
    {
        return toupper(key[c - 'A']);
    }
    else if(islower(c))
    {
        return tolower(key[c - 'a']);
    }
    else
    {
        return c;
    }
}