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
    int l, w, h, smallest, secondSmallest;
    int totalRibbon = 0;

    // Open the file in read mode
    file_ptr = fopen("input.txt", "r");

    // If the file is not found
    if (file_ptr == NULL)
    {
        printf("File not found\n");
        return 0;
    }

    totalRibbon = 0;

    // Total wrapping paper, loop through packages
    while (fgets(line, sizeof(line), file_ptr) != NULL)
    {
        // Split the line into tokens: l w h
        sscanf(line, "%dx%dx%d", &l, &w, &h);
        // Check the values
        printf("l: %d, w: %d, h: %d\n", l, w, h);

        // Calc smallest perimeter
        if (l < w)
        {
            smallest = l;
            secondSmallest = w;
        }
        else
        {
            smallest = w;
            secondSmallest = l;
        }

        // compare with the third number
        if (h < smallest)
        {
            secondSmallest = smallest;
            smallest = h;
        }
        else if (h < secondSmallest)
        {
            secondSmallest = h;
        }

        totalRibbon += 2 * smallest + 2 * secondSmallest;
        printf("Two smallest sides: %d %d\n", smallest, secondSmallest);
        printf("Total ribbon: %d\n", totalRibbon);

        int bow = l * w * h;
        printf("Bow: %d\n", bow);
        totalRibbon += bow;
    }

    printf("Total square feet of wrapping paper: %d\n", totalRibbon);

    fclose(file_ptr);
    return 0;
}
