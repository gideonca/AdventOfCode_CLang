#include<stdio.h>

int main() {
    FILE *file_ptr;
    char ch;
    file_ptr = fopen("input.txt", "r");
    if (NULL == file_ptr) {
        printf("file can't be opened \n");
        return 1;
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
    fclose(file_ptr);
    return 0;
}