#include <stdio.h>
#include<cs50.h>

int main(void)
{
    //Asks the user for input in the form of their name
    string name = get_string("What's your name?\n");

    //Prints out the salutation and the inputted name
    printf("\nHello, %s!\n", name);
}
