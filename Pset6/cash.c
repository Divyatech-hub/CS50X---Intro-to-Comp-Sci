#include <stdio.h>
#include <math.h>
#include <cs50.h>

float usdollars;
int coins = 0;

int main(void)
{
    //Prompt user for Cash owed and keep doing it until a positive number received
    do
    {
        usdollars = get_float("Cash owed: ");
    }
    while (usdollars <= 0);

    //Round the cents to the nearest penny as an integer
    int cents = round(usdollars * 100);

    //looping to deducte the values from the bigger to the smaller
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            cents = cents - 5;
        }
        else
        {
            cents --;
        }
        coins++;
    }
    //Print the minimal amount of coins for user
    printf("%i\n", coins);
}
