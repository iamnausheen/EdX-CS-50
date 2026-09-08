#include <cs50.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>

int digits(long);
int sum1(long, int);
int sum2(long, int);
int check_digits(long, int, int, int, ...);

int main(void)
{
    long ccn = get_long("Number : ");
    int nd = digits(ccn);
    int first_sum = sum1(ccn, nd);
    int second_sum = sum2(ccn, nd);
    int status = (first_sum + second_sum) % 10;
    int cd_AMEX = check_digits(ccn, nd, 2, 2, 34, 37);
    int cd_MASTERCARD = check_digits(ccn, nd, 2, 5, 51, 52, 53, 54, 55);
    int cd_VISA = check_digits(ccn, nd, 1, 1, 4);

    if ( cd_AMEX == 1 && nd == 15 && status == 0)
        printf("AMEX\n");
    else if (cd_MASTERCARD == 1 && nd == 16 && status == 0)
        printf("MASTERCARD\n");
    else if(cd_VISA == 1 && (nd == 13 || nd ==16) && status == 0)
        printf("VISA\n");
    else
        printf("INVALID\n");

    //Without check_digit function
    //long x = pow(10, nd-2);
    //int y = ccn/x;
    //if ((y == 34 || y == 37) && nd == 15 && status == 0)
        //printf("AMEX\n");
    //else if ((y >= 51 && y <= 55) && nd == 16 && status == 0)
        //printf("MASTERCARD\n");
    //else if ((y >= 40 && y < 50) && (nd == 13 || nd == 16) && status == 0)
        //printf("VISA\n");
    //else
        //printf("INVALID\n");
}

// Checking initial digits
int check_digits(long ccn, int nd, int id, int numArgs ,...)
{
    long x = pow(10, nd - id);
    int y = ccn / x;
    int z = 0;
    va_list args;
    va_start(args, numArgs);

    for(int i=0; i < numArgs; i++)
    {
        int num = va_arg(args, int);
        if (y==num)
            z = 1;
    }
    va_end(args);
    return z;
}

 // Sum of every other credit card digit
int sum1(long ccn, int nd)
{
    int j = 1;
    int sum = 0;
    int d;
    for (int i = 0; i < nd; i++)
    {
        d = ccn % 10;

        if ((j % 2) != 0 || j == 1)
        {
            sum = sum + d;
        }
        j++;
        ccn = ccn / 10;
    }
    return sum;
}

// Doubling and adding every other digit of credit card number
int sum2(long ccn, int nd)
{
    int sum = 0;
    int d;
    int j = 1;
    for (int i = 0; i < nd; i++)
    {
        d = ccn % 10;

        if ((j % 2) == 0)
        {
            int x = (2 * d) % 10;
            int y = (2 * d) / 10;
            sum = sum + x + y;
        }
        j++;
        ccn = ccn / 10;
    }
    return sum;
}

// Calculate number of digits in the credit card number
int digits(long ccn)
{
    int i = 0;
    long x;
    do
    {
        x = ccn / 10;
        ccn = ccn / 10;
        i++;
    }
    while (x != 0);

    return i;
}


