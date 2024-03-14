#include <cs50.h>
#include <stdio.h>

void print_spaces(int n);
void print_hashes(int n);

int main(void)
{
    int size;
    do
    {
        size = get_int("Height: ");
    }
    while(size < 1 || size > 8);

    for(int i = 0; i < size; i++)
    {
        print_spaces(size - i - 1);
        print_hashes(i + 1);
        print_spaces(2);
        print_hashes(i + 1);
        printf("\n");
    }
}

void print_spaces(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_hashes(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("#");
    }
}