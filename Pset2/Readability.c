#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Variables
    string text;
    int c;
    float letters;
    float words;
    float sentences;
    float L;
    float S;
    float index;


    // Get sentence

    {
        text = get_string("Text:");

        //Initiate
        c = letters = words = sentences = L = S = 0;
    }

    // Count letters, words, and sentences
    {
        while (text[c] != '\0')
        {
            if ((text[c] >= 'a' && text[c] <= 'z') || (text[c] >= 'A' && text[c] <= 'Z'))
            {
                letters++;
            }
            if (text[c] == ' ')
            {
                words++;
            }
            if ((text[c] == '.') || (text[c] == '!') || (text[c] == '?'))
            {
                sentences++;
            }
            {
                c++;
            }

        }
        //Add 1 extra word count
        {
            words++;
        }
        //Calculate L and S
        {
            L = (letters / words * 100);
            S = (sentences / words * 100);
        }
        // Cloeman-Liau Index
        {
            index = 0.0588 * L - 0.296 * S - 15.8;
        }

        if (index < 1)
        {
            printf("Before Grade \n");
        }
        else if (index >= 16)
        {
            printf("Grade 16+\n");
        }

        else
        {
            // printf("Reading level %.2f\n",index);
            printf("Grade %g\n", round(index));
        }
    }
}