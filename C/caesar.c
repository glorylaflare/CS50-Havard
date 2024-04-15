#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_args(string args);
void get_cipher(int arg);
void generate_cipherchar(int caesar_number, int max_number);
bool error(void);

int main(int argc, string argv[])
{
    bool test = false;
    if (argc == 2)
    {
        test = (check_args(argv[1]) == false) ? error() : (get_cipher(atoi(argv[1])), true);
    }

    if(test == false)
    {
        error();
        return 1;
    }

    printf("\n");
}

bool check_args(string args)
{
    bool only_numbers = true;
    for (int i = 0, n = strlen(args); i < n; i++)
    {
        if(args[i] < '0' || args[i] > '9')
        {
            only_numbers = false;
        }
    }

    return only_numbers;
}

void get_cipher(int arg)
{
    int max_number;
    int key_number = arg - (26 * (arg / 26));
    string text = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int caesar_number = text[i] + key_number;
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            max_number = 90;
            generate_cipherchar(caesar_number, max_number);
        }
        else if (text[i] >= 'a' && text[i] <= 'z')
        {
            max_number = 122;
            generate_cipherchar(caesar_number, max_number);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
}

void generate_cipherchar(int caesar_number, int max_number)
{
    if (caesar_number > max_number)
    {
        int cipherchar = caesar_number % (max_number + 1);
        printf("%c", (max_number - 25) + cipherchar);
    }
    else
    {
        printf("%c", caesar_number);
    }
}

bool error(void)
{
    printf("Usage: ./caesar key");
    return false;
}
