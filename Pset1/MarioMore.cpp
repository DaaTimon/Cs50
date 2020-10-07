    //Technically Mario More (Testing how I made reverse pyramid)

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Variables
    int i;
    int j;
    int k;
    int n;

    // Prompt number 1-8
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // i controls #rows, j and printf(1 space) control orientation/spacing, and k controls hashes
    for (i = 1; i <= n; i++)
    {
        for (j = (n - i); j > 0; j--)
        {
            printf(" ");
        }
        for (k = 1; k < (i + 1); k++)
        {
            printf("#");
        }
        
        // printf("2 spaces") standardizes 2 spaces per line
        {
            printf("  ");
        }
        
        // Below controls 
        for (k = 1; k < (i + 1); k++)
        {
            printf("#");
        }
        printf("\n");
    }
}