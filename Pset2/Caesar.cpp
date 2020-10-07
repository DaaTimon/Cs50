#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])

{
    //Variables
    //int cipher;
    //int encrypt;
    //char text;
    //int letters;
    int i;
    int ai;
    int ci;
    int cipher;
    int decrypt;
    char final;


    {

        if (argc != 2)
        {
            printf("./caesar key\n");
            return 1;
        }

        else

        {
            char str[20];

            printf("plaintext:");
            scanf("%s", str);
            {
                cipher = atoi(argv[1]);
            }

// ONLY LOWERCASE WORKING
            {
                printf("ciphertext: ");
            }

            {

                for (i = 0; str[i] != '\0'; i++)


                    if (str[i] >= 'a' && str[i] <= 'z')
                    {
                        ai = str[i] - 'a';
                        ci = (ai + cipher) % 26;
                        decrypt = ci + 'a';
                        final = decrypt;
                        printf("%c", final);
                    }
                    else if (str[i] >= 'A' && str[i] <= 'Z')
                    {
                        ai = str[i] - 'A';
                        ci = (ai + cipher) % 26;
                        decrypt = ci + 'A';
                        final = decrypt;
                        printf("%c", final);
                    }
                    else if (str[i] == ',')
                    {
                        printf(",");
                    }
                    else if (str[i] == '!')
                    {
                        printf("!");
                    }
                    else if (str[i])
                    {
                        printf(" ");
                    }
                {
                    printf("\n");

                }
            }
        }
    }
}