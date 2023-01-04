#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    while(num <1 || num>8);

    for(int i = 1; i<=num; i++)//rows
    {
        for (int j = 1; j <=(num); j++)
        {
            if(j <=(num-i))//adds the spaces
            {
                printf(" ");
            }
            else
            {
                printf("#");//adds the hashtags
            }
            printf("  ");
            printf("#");
        }
        printf("\n");
    }
}
