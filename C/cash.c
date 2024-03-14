#include <cs50.h>
#include <stdio.h>
#include <math.h>

void get_change(float cash);

int main(void)
{
    float cash;
    do
    {
        cash = get_float("How much money for change: ");
    } while(cash < 0);

    get_change(cash);
}

void get_change(float cash)
{
    int cash_in_cents = (int)(cash * 100);
    int coin_values[] = {25, 10, 5, 1};

    for(int i = 0; i < 4; i++)
    {
        int quant_coins = cash_in_cents / coin_values[i];
        int cash_left = quant_coins * coin_values[i];
        cash_in_cents = cash_in_cents - cash_left;

        printf("%iC:%i\n", coin_values[i], quant_coins);
    }
}