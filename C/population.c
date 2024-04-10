#include <cs50.h>
#include <stdio.h>

void get_years(int i_num, int f_num);

int main(void)
{
    int initial_size;
    int final_size;
    do
    {
        initial_size = get_int("Start size: ");
        if (initial_size < 9)
        {
            printf("The number must be greater than 9.");
        }
    }
    while (initial_size < 9);

    do
    {
        final_size = get_int("Final size: ");
        if (final_size < initial_size)
        {
            printf("The number must be greater or equal than the initial number.");
        }
    }
    while (final_size < initial_size);

    get_years(initial_size, final_size);
}

void get_years(int i_num, int f_num)
{
    int y, calc;
    for (y = 0; i_num < f_num; y++)
    {
        calc = i_num / 3 - i_num / 4;
        i_num += calc;
    }

    printf("Years: %i\n", y);
}
