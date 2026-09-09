#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height; j++)
        {
            int grey_shade = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);
            image[i][j].rgbtRed = grey_shade;
            image[i][j].rgbtGreen = grey_shade;
            image[i][j].rgbtBlue = grey_shade;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        int k = width - 1;
        for (int j = 0; j < width/2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][k];
            image[i][k] = temp;
            k--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Top left corner
            if (i == 0 && j == 0)
            {
                  image[i][j].rgbtRed = round((copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed +   copy[i + 1][j].rgbtRed +   copy[i + 1][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen)/4.0);
                 image[i][j].rgbtBlue = round((copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue +  copy[i + 1][j].rgbtBlue +  copy[i + 1][j + 1].rgbtBlue)/4.0);

            }
            // Top right corner
            else if (i == 0 && j == width - 1)
            {
                  image[i][j].rgbtRed = round((copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i + 1][j - 1].rgbtRed +   copy[i + 1][j].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen)/4.0);
                 image[i][j].rgbtBlue = round((copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i + 1][j - 1].rgbtBlue +  copy[i + 1][j].rgbtBlue)/4.0);
            }
            // Bottom left corner
            else if (i == height - 1 && j == 0)
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j].rgbtRed +   copy[i - 1][j + 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen)/4.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j].rgbtBlue +  copy[i - 1][j + 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue)/4.0);
            }
            // Bottom right corner
            else if (i == height - 1 && j == width - 1)
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed +   copy[i - 1][j].rgbtRed +   copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed)/4.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen)/4.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue +  copy[i - 1][j].rgbtBlue +  copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue)/4.0);
            }
            // Top edge
            else if (i == 0 && (j != 0 && j != width - 1))
            {
                  image[i][j].rgbtRed = round((copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed +   copy[i + 1][j - 1].rgbtRed +   copy[i + 1][j].rgbtRed +   copy[i + 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen)/6.0);
                 image[i][j].rgbtBlue = round((copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue +  copy[i + 1][j - 1].rgbtBlue +  copy[i + 1][j].rgbtBlue +  copy[i + 1][j + 1].rgbtBlue)/6.0);
            }
            // Bottom edge
            else if (i == height - 1 && (j != 0 && j != width - 1))
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed +   copy[i - 1][j].rgbtRed +   copy[i - 1][j + 1].rgbtRed +   copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen)/6.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue +  copy[i - 1][j].rgbtBlue +  copy[i - 1][j + 1].rgbtBlue +  copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue)/6.0);
            }
            // Left edge
            else if (j == 0 && (i != 0 && i != height - 1))
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j].rgbtRed +   copy[i - 1][j + 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed +   copy[i + 1][j].rgbtRed +   copy[i + 1][j + 1].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen)/6.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j].rgbtBlue +  copy[i - 1][j + 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue +  copy[i + 1][j].rgbtBlue +  copy[i + 1][j + 1].rgbtBlue)/6.0);
            }
            // Right edge
            else if (j == width - 1 && (i != 0 && i != height - 1))
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed +   copy[i - 1][j].rgbtRed +   copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i + 1][j - 1].rgbtRed +   copy[i + 1][j].rgbtRed)/6.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen)/6.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue +  copy[i - 1][j].rgbtBlue +  copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i + 1][j - 1].rgbtBlue +  copy[i + 1][j].rgbtBlue)/6.0);
            }
            // Middle
            else
            {
                  image[i][j].rgbtRed = round((copy[i - 1][j - 1].rgbtRed +   copy[i - 1][j].rgbtRed +   copy[i - 1][j + 1].rgbtRed +   copy[i][j - 1].rgbtRed +   copy[i][j].rgbtRed +   copy[i][j + 1].rgbtRed +   copy[i + 1][j - 1].rgbtRed +   copy[i + 1][j].rgbtRed +   copy[i + 1][j + 1].rgbtRed)/9.0);
                image[i][j].rgbtGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen)/9.0);
                 image[i][j].rgbtBlue = round((copy[i - 1][j - 1].rgbtBlue +  copy[i - 1][j].rgbtBlue +  copy[i - 1][j + 1].rgbtBlue +  copy[i][j - 1].rgbtBlue +  copy[i][j].rgbtBlue +  copy[i][j + 1].rgbtBlue +  copy[i + 1][j - 1].rgbtBlue +  copy[i + 1][j].rgbtBlue +  copy[i + 1][j + 1].rgbtBlue)/9.0);
            }
        }
    }
    return;
}


// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height + 2][width + 2];

    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i != 0 && i != height  )
                copy[i][j] = image[i][j];
        }
    }

    // Gx
    int Gx_weights[3][3];
    Gx_weights[0][0] = -1;
    Gx_weights[0][1] = 0;
    Gx_weights[0][2] = 1;
    Gx_weights[1][0] = -2;
    Gx_weights[1][1] = 0;
    Gx_weights[1][2] = 2;
    Gx_weights[2][0] = -1;
    Gx_weights[2][1] = 0;
    Gx_weights[2][2] = 1;

    // Gy
    int Gy_weights[3][3];
    Gy_weights[0][0] = -1;
    Gy_weights[0][1] = -2;
    Gy_weights[0][2] = -1;
    Gy_weights[1][0] = 0;
    Gy_weights[1][1] = 0;
    Gy_weights[1][2] = 0;
    Gy_weights[2][0] = 1;
    Gy_weights[2][1] = 2;
    Gy_weights[2][2] = 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i != 0 && i != height && j != 0 && j != width)
            {
                // Gx
                int Gx[3] = {0, 0, 0};
                Gx[0] =   copy[i -1][j - 1].rgbtRed*Gx_weights[0][0] +   copy[i -1][j].rgbtRed*Gx_weights[0][1] +   copy[i -1][j + 1].rgbtRed*Gx_weights[0][2] +   copy[i][j - 1].rgbtRed*Gx_weights[1][0] +   copy[i][j].rgbtRed*Gx_weights[1][1] +   copy[i][j + 1].rgbtRed*Gx_weights[1][2] +   copy[i + 1][j - 1].rgbtRed*Gx_weights[2][0] +   copy[i + 1][j].rgbtRed*Gx_weights[2][1] +   copy[i + 1][j + 1].rgbtRed*Gx_weights[2][2] ;
                Gx[1] = copy[i -1][j - 1].rgbtGreen*Gx_weights[0][0] + copy[i -1][j].rgbtGreen*Gx_weights[0][1] + copy[i -1][j + 1].rgbtGreen*Gx_weights[0][2] + copy[i][j - 1].rgbtGreen*Gx_weights[1][0] + copy[i][j].rgbtGreen*Gx_weights[1][1] + copy[i][j + 1].rgbtGreen*Gx_weights[1][2] + copy[i + 1][j - 1].rgbtGreen*Gx_weights[2][0] + copy[i + 1][j].rgbtGreen*Gx_weights[2][1] + copy[i + 1][j + 1].rgbtGreen*Gx_weights[2][2];
                Gx[2] =  copy[i -1][j - 1].rgbtBlue*Gx_weights[0][0] +  copy[i -1][j].rgbtBlue*Gx_weights[0][1] +  copy[i -1][j + 1].rgbtBlue*Gx_weights[0][2] +  copy[i][j - 1].rgbtBlue*Gx_weights[1][0] +  copy[i][j].rgbtBlue*Gx_weights[1][1] +  copy[i][j + 1].rgbtBlue*Gx_weights[1][2] +  copy[i + 1][j - 1].rgbtBlue*Gx_weights[2][0] +  copy[i + 1][j].rgbtBlue*Gx_weights[2][1] +  copy[i + 1][j + 1].rgbtBlue*Gx_weights[2][2];

                // Gy
                int Gy[3] = {0, 0, 0};
                Gy[0] =   copy[i -1][j - 1].rgbtRed*Gy_weights[0][0] +   copy[i -1][j].rgbtRed*Gy_weights[0][1] +   copy[i -1][j + 1].rgbtRed*Gy_weights[0][2] +   copy[i][j - 1].rgbtRed*Gy_weights[1][0] +   copy[i][j].rgbtRed*Gy_weights[1][1] +   copy[i][j + 1].rgbtRed*Gy_weights[1][2] + copy[i + 1][j - 1].rgbtRed*Gy_weights[2][0] +   copy[i + 1][j].rgbtRed*Gy_weights[2][1] +   copy[i + 1][j + 1].rgbtRed*Gy_weights[2][2] ;
                Gy[1] = copy[i -1][j - 1].rgbtGreen*Gy_weights[0][0] + copy[i -1][j].rgbtGreen*Gy_weights[0][1] + copy[i -1][j + 1].rgbtGreen*Gy_weights[0][2] + copy[i][j - 1].rgbtGreen*Gy_weights[1][0] + copy[i][j].rgbtGreen*Gy_weights[1][1] + copy[i][j + 1].rgbtGreen*Gy_weights[1][2] + copy[i + 1][j - 1].rgbtGreen*Gy_weights[2][0] + copy[i + 1][j].rgbtGreen*Gy_weights[2][1] + copy[i + 1][j + 1].rgbtGreen*Gy_weights[2][2];
                Gy[2] =  copy[i -1][j - 1].rgbtBlue*Gy_weights[0][0] +  copy[i -1][j].rgbtBlue*Gy_weights[0][1] +  copy[i -1][j + 1].rgbtBlue*Gy_weights[0][2] +  copy[i][j - 1].rgbtBlue*Gy_weights[1][0] +  copy[i][j].rgbtBlue*Gy_weights[1][1] +  copy[i][j + 1].rgbtBlue*Gy_weights[1][2] +  copy[i + 1][j - 1].rgbtBlue*Gy_weights[2][0] +  copy[i + 1][j].rgbtBlue*Gy_weights[2][1] +  copy[i + 1][j + 1].rgbtBlue*Gy_weights[2][2];

                int Gx_Gy[3] = {0, 0, 0};
                Gx_Gy[0] = round(sqrt(pow(Gx[0], 2) + pow(Gy[0], 2)));
                Gx_Gy[1] = round(sqrt(pow(Gx[1], 2) + pow(Gy[1], 2)));
                Gx_Gy[2] = round(sqrt(pow(Gx[2], 2) + pow(Gy[2], 2)));


                image[i][j].rgbtRed = Gx_Gy[0];
                image[i][j].rgbtGreen = Gx_Gy[1];
                image[i][j].rgbtBlue = Gx_Gy[2];

                if (image[i][j].rgbtRed > 255)
                    image[i][j].rgbtRed = 255;
                if (image[i][j].rgbtGreen > 255)
                    image[i][j].rgbtGreen = 255;
                if (image[i][j].rgbtBlue > 255)
                    image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}
