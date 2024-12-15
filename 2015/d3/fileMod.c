#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Open file
    FILE *file_ptr;

    // Character buffer that stores the read character
    // Till the next iteration
    char ch;

    // Open the file in read mode
    file_ptr = fopen("input.txt", "r");

    if (NULL == file_ptr)
    {
        printf("file can't be opened \n");
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(file_ptr)) != EOF)
    {
        switch (ch)
        {
        case '^':
            printf("U\n");
            break;
        case 'v':
            printf("D\n");
            break;
        case '<':
            printf("L\n");
            break;
        case '>':
            printf("R\n");
            break;
        default:
            break;
        }
    }

    fclose(file_ptr);

    return 0;
}
