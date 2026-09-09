#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

int main(int argc, char *argv[])
{
    // Define allowable filters
    char *filters = "bgrs";

    // Get filter flag and check validity
    char filter = getopt(argc, argv, filters);
    if (filter == '?')
    {
        printf("Invalid filter.\n");
        return 1;
    }
/*
# getopt helps to handle command line arguments
In the context of getopt(), parsing refers to the process of analyzing the command-line arguments
passed to a program. getopt() goes through the arguments
(typically given as argc and argv from the main() function one by one.
For each argument that starts with a '-' (which denotes an option),
getopt() checks if it's a valid option as per the option string provided.
If the option requires an argument (indicated by a ':' after the option in the option string),
getopt() also retrieves the argument following the option.
This way, getopt() helps in parsing command-line options and their arguments.

getopt(argc, argv[], option characters)

The getopt() function returns the index for the next command line option to be processed.
When all options have been processed, it returns -1.
If getopt() encounters an option character it doesn't recognize,
it returns '?' and sets the global variable optopt to the unrecognized option character.
If getopt() encounters an option that's missing a required argument,
it returns ':' and also sets optopt to the option character.

*/

    // Ensure only one filter
    if (getopt(argc, argv, filters) != -1)
    {
        printf("Only one filter allowed.\n");
        return 2;
    }

    // Ensure proper usage
    if (argc != optind + 2)
    {
        printf("Usage: ./filter [flag] infile outfile\n");
        return 3;
    }

/*
optind is a global variable used by getopt().
It represents the index of the next element to be processed in the argv array.
The system initializes this value to 1 before the program starts,
and then getopt() updates it every time it processes an option.
This allows your program to process additional command-line arguments that are not option arguments
after getopt() has finished processing the options.


optind is the index of the next argument to be processed by getopt().
When getopt() has finished processing all option arguments,
optind will be the index of the first non-option argument.
In the context of your program, you're expecting two non-option arguments (infile and outfile).
So, after all options have been processed, optind should be at the position just before infile.
Therefore, optind + 2 would be the total number of arguments: optind (all the options),
optind + 1 (infile), and optind + 2 (outfile).

If argc (the total number of command-line arguments) is not equal to optind + 2,
it means the user has not provided the correct number of arguments

If you use argc != 3, it will only work if your program expects exactly three arguments every time it runs,
including the program's name itself.
This would be suitable if your program always expects one option and one non-option argument.
However, if your program can have varying numbers of options,
using optind would be more flexible as it accounts for any number of options before the non-option arguments.
*/

    // Remember filenames
    char *infile = argv[optind];
    char *outfile = argv[optind + 1];

    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }

    // Open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 5;
    }

    // Read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // Read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        printf("Unsupported file format.\n");
        return 6;
    }

    // Get image's dimensions
    int height = abs(bi.biHeight);
    int width = bi.biWidth;


/*
It seems like you're trying to get the absolute value of the height of a bitmap image.
This is typically done when the image data might be stored upside down,
which is indicated by a negative height in the BITMAPINFOHEADER.
By taking the absolute value, you ensure that you're always working with a positive height.
*/

    // Allocate memory for image
    RGBTRIPLE(*image)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    if (image == NULL)
    {
        printf("Not enough memory to store image.\n");
        fclose(outptr);
        fclose(inptr);
        return 7;
    }

/*
The calloc function is used in C to dynamically allocate memory.
It takes two arguments: the number of elements to be allocated and the size of each element.
The function returns a pointer to the allocated memory.
The memory allocated by calloc is initialized to zero, which differentiates it from malloc,
another memory allocation function in C. If the allocation fails, calloc returns a NULL pointer.
*/

    // Determine padding for scanlines
    int padding = (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4;

/*
This line of code is calculating the padding for each row of an image.
In a bitmap file, each row needs to be a multiple of 4 bytes.
If the width of the image times the size of an RGBTRIPLE is not a multiple of 4,
some padding bytes (extra bytes of no meaningful data) are added to the end of each row to make it so.
The calculation (4 - (width * sizeof(RGBTRIPLE)) % 4) % 4 is determining how many of these padding bytes are needed.

The double modulus operation is used to handle the case where the row size is already a multiple of 4.
In this case, (width * sizeof(RGBTRIPLE)) % 4 would be 0, and 4 - 0 would be 4,
suggesting that 4 bytes of padding are needed. However, if the row size is already a multiple of 4,
no padding is needed.
The second modulus operation, % 4, turns this 4 into a 0, correctly indicating that no padding is needed.
*/

    // Iterate over infile's scanlines
    for (int i = 0; i < height; i++)
    {
        // Read row into pixel array
        fread(image[i], sizeof(RGBTRIPLE), width, inptr);

        // Skip over padding
        fseek(inptr, padding, SEEK_CUR);
    }

    // Filter image
    switch (filter)
    {
        // Blur
        case 'b':
            blur(height, width, image);
            break;

        // Grayscale
        case 'g':
            grayscale(height, width, image);
            break;

        // Reflection
        case 'r':
            reflect(height, width, image);
            break;

        // Sepia
        case 's':
            sepia(height, width, image);
            break;
    }

    // Write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // Write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Write new pixels to outfile
    for (int i = 0; i < height; i++)
    {
        // Write row to outfile
        fwrite(image[i], sizeof(RGBTRIPLE), width, outptr);

        // Write padding at end of row
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Free memory for image
    free(image);

    // Close files
    fclose(inptr);
    fclose(outptr);
    return 0;
}
