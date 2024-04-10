#include <cs50.h>
#include <stdio.h>
#include <math.h>

int get_sum_doubled_digits(long number);
int get_sum_remaining_digits(long number);
void verify_integrity(int sum, long number, int total_digits);

int main(void)
{
    long card_number = get_long("Card Number: ");
    long calc_digits = card_number;
    int i;
    for(i = 0; calc_digits > 0; i++)
    {
        calc_digits /= 10;
    }

    int validate_card = get_sum_doubled_digits(card_number / 10) +  get_sum_remaining_digits(card_number);
    verify_integrity(validate_card, card_number, i);
}

int get_sum_doubled_digits(long number)
{
    int sum = 0;
    int count = 8;
    while(count > 0)
    {
        int digit = (number % 10) * 2;
        if(digit >= 10)
        {
            int digit_1 = digit / 10;
            int digit_2 = digit % 10;
            sum = sum + digit_1 + digit_2;
        }
        else
        {
            sum += digit;
        }
        number /= 100;
        count--;
    }
    return sum;
}

int get_sum_remaining_digits(long number)
{
    int sum = 0;
    int count = 8;
    while(count > 0)
    {
        sum += number % 10;
        number /= 100;
        count--;
    }
    return sum;
}

void verify_integrity(int sum, long number, int total_digits)
{
    if(total_digits >= 13 && sum % 10 == 0)
    {
        long count_digits = number;
        int count = 0;
        while(count_digits != 0)
        {
            count_digits /= 10;
            count++;
        }
        long id_1 = number / pow(10, count-1);
        long id_2 = number / pow(10, count-2);
        if(id_1 == 4)
        {
            printf("VISA\n");
        }
        else if(id_1 == 5)
        {
            if(id_2 >= 51 && id_2 <= 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if(id_1 == 3)
        {
            if(id_2 == 34 || id_2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
