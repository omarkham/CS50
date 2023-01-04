#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    long number = get_long("Credit Card #: ");

    //to get the length of the input
    int i = 0;
    long cc = number;
    while(cc>0)
    {
        cc=cc/10;
        i++;
    }
    //for this question, length needs to be correct
    if (i != 13 && i!=15 && i !=16)
    {
        printf("INVALID\n");
        return 0;//same as return EXIT_FAILURE
    }

    //instead of using strings and arrays, you can just use mode and division
    //to get the last digit of the number
    int total_1 = 0;
    int total_2 = 0;
    int modulus_1;
    int modulus_2;
    long x = number;
    int real_total = 0;
    int p1=0;
    int p2=0;

    do
    {
        //add the last digit to total_1, then delete it
        modulus_1 = x%10;
        x = x/ 10;
        total_1 = total_1 + p1;

        //take away the second-last digit
        modulus_2 = x%10;
        x = x/10;

        //do 2*the second last_digit
        //add the digit to total_2
        modulus_2 = x*2;
        p1 = modulus_2 % 10;
        p2 = modulus_2 /10;
        total_2 = total_2 + p1 + p2;
    }
    while(x>0);
    real_total = total_1 + total_2;

    //now check to see if it passes the algorithm
    if(real_total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;//EXIT_FAILURE
    }

    //now we need to check what sort of card it is
    //so we need to get the first two digits to compare them
    long begin = number;
    do
    {
        begin = begin / 10;
    }
    while(begin>100);//100 since we want the first two(so it'll be a number with 2 digits)

    //mastercard starts with 51 - 55
    if (( begin / 10 == 5) && ((1 <= (begin%10)) && ((begin%10)  <=5)))
    {
        printf("MASTERCARD\n");
    }
    //american express starts with 34 or 37
    else if((begin/10 == 3) && (begin%10 == 4 || begin%10 == 7))
    {
        printf("AMEX\n");
    }
    else if(begin/10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}
