#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int shade = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);
            image[i][j].rgbtBlue = shade;
            image[i][j].rgbtGreen = shade;
            image[i][j].rgbtRed = shade;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepiaGreen = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepiaBlue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            if (sepiaGreen > 255)
                sepiaGreen = 255;
            if (sepiaRed > 255)
                sepiaRed = 255;
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int k = width - 1;
        for (int j = 0; j < (width/2); j++)
        {
                RGBTRIPLE temp = image[i][j];
                image[i][j] = image[i][k];
                image[i][k] = temp;
                k--;
        }
    }
    return;
}

// Functions for blur

// Calculate sum
int sum[3];

void calculate_sum(int l, int m, int location, int height, int width, RGBTRIPLE copy[height][width])
{
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 0;

    switch (location)
    {
        case 1:
            for (int i = l; i < (l + 2); i++)
            {
                for(int j = m; j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 2:
            for (int i = l; i < (l + 2); i++)
            {
                for (int j = (m - 1); j < (m + 1); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 3:
            for (int i = (l - 1); i < (l + 1); i++)
            {
                for (int j = m; j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 4:
            for (int i = (l - 1); i < (l + 1); i++)
            {
                for (int j = (m - 1); j < (m + 1); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 5:
            for (int i = l; i < (l + 2); i++)
            {
                for (int j = (m - 1); j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 6:
            for (int i = (l - 1); i < (l + 1); i++)
            {
                for (int j = (m - 1); j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 7:
            for (int i = (l - 1); i < (l + 2); i++)
            {
                for (int j = m; j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 8:
            for (int i = (l - 1); i < (l + 2); i++)
            {
                for (int j = (m - 1); j < (m + 1); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;

        case 9:
            for (int i = (l - 1); i < (l + 2); i++)
            {
                for (int j = (m - 1); j < (m + 2); j++)
                {
                    sum[0] += copy[i][j].rgbtRed;
                    sum[1] += copy[i][j].rgbtGreen;
                    sum[2] += copy[i][j].rgbtBlue;
                }
            }
            break;
    }
    return;
}

// calculate average

int average[3];

void calculate_average(int l)
{
    average[0] = 0;
    average[1] = 0;
    average[2] = 0;

    switch(l)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            average[0] = round(sum[0]/4.0);
            average[1] = round(sum[1]/4.0);
            average[2] = round(sum[2]/4.0);
            break;

        case 5:
        case 6:
        case 7:
        case 8:
            average[0] = round(sum[0]/6.0);
            average[1] = round(sum[1]/6.0);
            average[2] = round(sum[2]/6.0);
            break;

        case 9:
            average[0] = round(sum[0]/9.0);
            average[1] = round(sum[1]/9.0);
            average[2] = round(sum[2]/9.0);
    }

    // Capping values at 255
    if (average[0] > 255)
        average[0] = 255;
    if (average[1] > 255)
        average[1] = 255;
    if (average[2] > 255)
        average[2] =255;

    return;
}

// location function
int location(int i, int j, int height, int width)
{
    int location = 0;
    if (i == 0 && j == 0)
        //location = "upper left corner";
        location = 1;
    else if (i == 0 && j == (width - 1))
        //location = "upper right corner";
        location = 2;
    else if (i == (height - 1) && j == 0)
        //location = "lower left corner";
        location = 3;
    else if (i == (height - 1) && j == (width - 1))
        //location = "lower right corner";
        location = 4;
    else if (i == 0 && (j != 0 && j != (width - 1)))
       // location = "upper edge";
       location = 5;
    else if (i == (height - 1) && (j != 0 && j != (width - 1)))
        //location = "lower edge";
        location = 6;
    else if (j == 0 && (i != 0 && i != (height - 1)))
        // location = "left edge";
        location = 7;
    else if (j == (width - 1) && (i != 0 && i != (height - 1)))
        // location = "right edge";
        location = 8;
    else
        //location = "middle";
        location = 9;
    return location;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Make copy
            copy[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Finding location
            int l = location(i, j, height, width);

            // Calculating sum
            calculate_sum(i, j, l, height, width, copy);

            // Calculating average
            calculate_average(l);

            // Assign average
            image[i][j].rgbtRed = average[0];
            image[i][j].rgbtGreen = average[1];
            image[i][j].rgbtBlue = average[2];
        }
    }
    return;
}

