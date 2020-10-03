#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Variables
    long number;
    //First set of Checksum multiplied by 2
    long checksum1;
    long checksum2;
    long checksum3;
    long checksum4;
    long checksum5;
    long checksum6;
    long checksum7;
    long checksum8;
    long checksum1f;
    long checksum2f;
    long checksum3f;
    long checksum4f;
    long checksum5f;
    long checksum6f;
    long checksum7f;
    long checksum8f;
    long set2;
    //Second set of Checksum with no multiplication
    long checksum9;
    long checksum10;
    long checksum11;
    long checksum12;
    long checksum13;
    long checksum14;
    long checksum15;
    long checksum16;
    long set1;
    // Adding ChecksumS1 and S2
    long set;
    //Verify ends in 0
    long verify;

    // Get Card Number

    {
        number = get_long("Input card number:");

    }

    // Checksum

    //Set1
    {
        checksum1 = (number % 100 / 10) * 2;
        checksum1f = ((checksum1 % 10) + (checksum1 % 100 / 10));
    }
    {
        checksum2 = (number % 10000 / 1000) * 2;
        checksum2f = ((checksum2 % 10) + (checksum2 % 100 / 10));
    }
    {
        checksum3 = (number % 1000000 / 100000) * 2;
        checksum3f = ((checksum3 % 10) + (checksum3 % 100 / 10));
    }
    {
        checksum4 = (number % 100000000 / 10000000) * 2;
        checksum4f = ((checksum4 % 10) + (checksum4 % 100 / 10));
    }
    {
        checksum5 = (number % 10000000000 / 1000000000) * 2;
        checksum5f = ((checksum5 % 10) + (checksum5 % 100 / 10));
    }
    {
        checksum6 = (number % 1000000000000 / 100000000000) * 2;
        checksum6f = ((checksum6 % 10) + (checksum6 % 100 / 10));
    }
    {
        checksum7 = (number % 100000000000000 / 10000000000000) * 2;
        checksum7f = ((checksum7 % 10) + (checksum7 % 100 / 10));
    }
    {
        checksum8 = (number % 10000000000000000 / 1000000000000000) * 2;
        checksum8f = ((checksum8 % 10) + (checksum8 % 100 / 10));
    }

    {
        set1 = (checksum1f + checksum2f + checksum3f + checksum4f + checksum5f + checksum6f + checksum7f + checksum8f);

    }

    //Set 2
    {
        checksum9 = (number % 10);

    }

    {
        checksum10 = (number % 1000 / 100);

    }

    {
        checksum11 = (number % 100000 / 10000);

    }

    {
        checksum12 = (number % 10000000 / 1000000);
    }

    {
        checksum13 = (number % 1000000000 / 100000000);

    }

    {
        checksum14 = (number % 100000000000 / 10000000000);
    }

    {
        checksum15 = (number % 10000000000000 / 1000000000000);
    }

    {
        checksum16 = (number % 1000000000000000 / 100000000000000);
    }

    {
        set2 = (checksum9 + checksum10 + checksum11 + checksum12 + checksum13 + checksum14 + checksum15 + checksum16);

    }

    // Add the two sets
    {
        set = (set1 + set2);

    }

    //Verify ending in 0
    {
        verify = (set % 10);
    }

    if (verify == 0)

    {
        // Determine Brand of Card

        if (number >= 340000000000000 && number <= 349999999999999)
        {
            printf("AMEX\n");
        }
        else if (number >= 370000000000000 && number <= 379999999999999)
        {
            printf("AMEX\n");
        }
        else if (number >= 5100000000000000 && number <= 5599999999999999)
        {
            printf("MASTERCARD\n");
        }
        else if (number >= 4000000000000 && number <= 4999999999999)
        {
            printf("VISA\n");
        }
        else if (number >= 4000000000000000 && number <= 4999999999999999)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}