#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage : ./recover card.raw\n");
        return 1;
    }

    // Open card
    FILE* card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("ERROR! Couldn't read card\n");
        return 2;
    }

    int count = 0;
    uint8_t buffer[512];
    FILE* copy = NULL;
    char name[8];

    while (fread(buffer, 1, 512, card) == 512) // fread(buffer, 512, 1, card) returns 1 not 512
    {
        // Look for jpeg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (copy != NULL)
            {
                fclose(copy);
            }

            sprintf(name, "%03i.jpg", count++);

            copy = fopen(name, "w");
            if (copy == NULL)
            {
                printf("Memory Error\n");
                return 3;
            }

            fwrite(buffer, 512, 1, copy);

        }

        else
        {
            if (copy != NULL)
            {
                fwrite(buffer, 512, 1, copy);
            }
        }
    }

    if (copy != NULL)
    {
        fclose(copy);
    }

    fclose(card);
    return 0;
}




