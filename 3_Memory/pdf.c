// Finding if a file is a pdf or not
#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./pdf filename\n");
        return 1;
    }
    // There is specicfic information about the type of file in the beginning of each file
    // For a pdf file, first 4 bytes are the int value : 37, 80, 68, 70

    string filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Couldn't open file\n");
        return 2;
    }
    uint8_t buffer[4];
    // or int buffer as an integer is 4 bytes long, adjust fread, it is important to make sure the buffer is the same size as we want to read

    int blocks_read = fread(&buffer, 1, 4, file);

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    printf("%i\n", blocks_read);

    fclose(file);



}
