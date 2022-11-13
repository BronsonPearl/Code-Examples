#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int years = 0;
    int startSize = 0;
    int endSize = 0;

    // TODO: Prompt for start size
    // prompts for an int input.  will do repeated until user enters a number greater or equal to 9
    do
    {
        startSize = get_int("llama start size: \n");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    // prompts for an in input.  will repeat until user enters a number greater or equal to startSize

    do
    {
        endSize = get_int("llama end size: \n");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold

    while (startSize < endSize)
    {

        startSize = startSize + ((startSize / 3) - (startSize / 4));

        years++;


    }

    // TODO: Print number of years
    printf("Years: %i", years);

}