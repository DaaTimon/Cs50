#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main(int argc, char *argv[])
{
    // Check Command Line Argument
    typedef uint8_t BYTE;

    if (argc != 2)
    {
        printf("./recover image\n");
        return 1;
    }

    // Open file
    FILE *f = fopen(argv[1], "rb");

    // Check if opened
    if (f == NULL)
    {
        printf("./recover image\n");
        return 1;
    }
    // Set variables, allocate for jpg and initialize filecounter

    BYTE buffer[512];
    FILE *img = NULL;
    char *jpg = NULL;
    jpg = (char *)malloc(8 * sizeof(char));

    int filecounter = 0;

    // Check buffer and confirm starts like .jpg
    while (fread(buffer, sizeof(BYTE), 512, f) == 512)

    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Make (string print) .jpg, write to it, then proceed to next file
            if (filecounter == 0)
            {
                sprintf(jpg, "%03i.jpg", filecounter);
                img = fopen(jpg, "w");

                fwrite(buffer, sizeof(BYTE), 512, img);
                filecounter++;
            }
            else
            {
                // Close previous img then do the same thing as above
                fclose(img);
                sprintf(jpg, "%03i.jpg", filecounter);
                img = fopen(jpg, "w");

                fwrite(buffer, sizeof(BYTE), 512, img);
                filecounter++;
            }
        }
        // If filecounter is greater than 0 write
        else if (filecounter > 0)
        {
            fwrite(buffer, sizeof(BYTE), 512, img);
        }
    }
    // Close off everything and send completion
    fclose(img);
    fclose(f);
    return 0;
}