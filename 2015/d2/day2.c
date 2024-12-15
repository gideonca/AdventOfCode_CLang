#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Algorithm to calculate the wrapping paper
// 2*l*w + 2*w*h + 2*h*lp

int main()
{
    // Open file
    FILE *file_ptr;

    // Character buffer that stores the read character
    // Till the next iteration
    char line[256];
    int l, w, h;
    int totalSquareFeet = 0;

    // Open the file in read mode
    file_ptr = fopen("input.txt", "r");

    // If the file is not found
    if (file_ptr == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    // Total wrapping paper, loop through packages
    while (fgets(line, sizeof(line), file_ptr) != NULL)
    {
        // Split the line into tokens: l w h
        sscanf(line, "%dx%dx%d", &l, &w, &h);
        // Check the values
        printf("l: %d, w: %d, h: %d\n", l, w, h);
        totalSquareFeet += ((2 * l * w) + (2 * w * h) + (2 * h * l));

        // Find total square feet
        printf("Sum total square feet: %d\n", totalSquareFeet);

        // Find the smallest side
        int min = l*w;
        if (w*h < min)
        {
            min = w*h;
        }
        if (h*l < min)
        {
            min = h*l;
        }

        printf("Smallest side: %d\n", min);
        totalSquareFeet += min;
        printf("Adjusted total square feet: %d\n", totalSquareFeet);
    }

    printf("Total square feet of wrapping paper: %d\n", totalSquareFeet);

    fclose(file_ptr);
    return 0;
}
