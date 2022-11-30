#include <stdio.h>
#include <cs50.h>

void pym_gen(int Height, int startHeight);

int main(void)
{
    int h;
    //Ask user for pyramid height and keep doing it until a valid integer positive given (between 1-8)
    do
    {
        h = get_int("What's is the height for the pyramid?(1-8):  \n");
    } 
    while (h < 1 || h > 8);

    pym_gen(h, h);
}

// function to generate the right-allighed pyramid of #s 

void pym_gen(int Height, int startHeight)
{
    if (Height == 0)
    {
        return;
    }
    pym_gen(Height - 1, startHeight);

    for (int i = 0; i < startHeight - Height; i++)
    {
        printf(" ");             // this line helps us decide no of spaces needed per iteration
    }
    for (int i = 0; i < Height; i++)
    {
        printf("#");            // here we decide the number of # per iteration 
    }
    printf("\n");              // taking the cursor to beginning of next line for next iteration 
}
