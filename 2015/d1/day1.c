#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open file
    FILE *file_ptr;

    // Character buffer that stores the read character
    // Till the next iteration
    char ch;

    // Open the file in read mode
    file_ptr = fopen("input.txt", "r");

    if (NULL == file_ptr) {
        printf("file can't be opened \n");
        return EXIT_FAILURE;
    }

    int target_floor = 0;

    while ((ch = fgetc(file_ptr)) != EOF) {
        if (ch == '(') {
            target_floor++;
        } else if (ch == ')') {
            target_floor--;
        }
    }

    printf("The target floor is: %d\n", target_floor);

    return 0;

}
