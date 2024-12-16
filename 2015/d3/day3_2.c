#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store coordinates of a point
typedef struct Point
{
    int x;
    int y;
} Point;

// Function to print a point
void printPoint(Point p)
{
    printf("(%d, %d)\n", p.x, p.y);
}

// Function to check if a point is already in the list of visited points
int isPointVisited(Point *visitedPoints, int numVisited, Point p)
{
    for (int i = 0; i < numVisited; i++)
    {
        if (visitedPoints[i].x == p.x && visitedPoints[i].y == p.y)
        {
            return 1; // Point already visited
        }
    }
    return 0; // Point not visited
}

char *getFileContent()
{
    // Initialize the buffer to NULL
    char *buffer = NULL;
    int buffer_size = 1000; // Initial buffer size
    int c, i = 0;

    // Allocate initial memory for the buffer
    buffer = malloc(buffer_size);
    if (buffer == NULL)
    {
        printf("Error allocating memory\n");
        return NULL;
    }

    // Open file in read mode
    FILE *file_ptr = fopen("data.txt", "r");
    if (file_ptr == NULL)
    {
        printf("file can't be opened \n");
        free(buffer); // Free the allocated memory
        return NULL;
    }

    // Read the file character by character
    while ((c = fgetc(file_ptr)) != EOF)
    {
        // If buffer is full, resize it
        if (i >= buffer_size - 1)
        {                        // -1 to leave space for null terminator
            buffer_size += 1000; // Resize by 1000 bytes
            char *new_buffer = realloc(buffer, buffer_size);
            if (new_buffer == NULL)
            {
                printf("Error reallocating memory\n");
                free(buffer); // Free the old buffer
                fclose(file_ptr);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[i] = c;
        i++;
    }

    // Null-terminate the buffer
    if (buffer != NULL)
    {
        buffer[i] = '\0';
    }

    // Close the file
    fclose(file_ptr);

    return buffer;
}

int main()
{
    int numDirections;

    // Array to store visited points
    int numVisited = 0;

    Point currentPosition = {0, 0}; // Start at origin
    printf("Starting at: ");
    printPoint(currentPosition);

    char *content = getFileContent();
    printf("Content: %s\n", content);

    // Array to store visited points
    int size = strlen(content);
    Point *visited = malloc(size * sizeof(Point));

    // Split the content into two routes
    int split_route = strlen(content);

    // Create char arrays for Santa and Robo-Santa
    char *santa_route = malloc((split_route / 2 + 1) * sizeof(char));
    char *robo_santa_route = malloc((split_route / 2 + 1) * sizeof(char));

    // Check if memory allocation failed
    if (santa_route == NULL || robo_santa_route == NULL)
    {
        printf("Memory allocation failed\n");
        free(content);
        return EXIT_FAILURE;
    }

    // Split the content into two routes
    for (int i = 0; i < split_route; i++)
    {
        if (i % 2 == 0)
        {
            santa_route[i / 2] = content[i];
        }
        else
        {
            robo_santa_route[i / 2] = content[i];
        }
    }

    // Null-terminate the routes
    santa_route[split_route / 2] = '\0';
    robo_santa_route[split_route / 2] = '\0';

    // Split routes between the two
    printf("Santa's route: %s\n", santa_route);
    printf("Robo-Santa's route: %s\n", robo_santa_route);

    for (int i = 0; i < split_route / 2; i++)
    {
        char direction = santa_route[i];

        switch (direction)
        {
        case '^':
            currentPosition.y += 1;
            break;
        case 'v':
            currentPosition.y -= 1;
            break;
        case '<':
            currentPosition.x -= 1;
            break;
        case '>':
            currentPosition.x += 1;
            break;
        default:
            printf("Invalid direction: %c\n", direction);
        }

        // Check if the current position has been visited
        if (!isPointVisited(visited, numVisited, currentPosition))
        {
            visited[numVisited] = currentPosition;
            numVisited++;
        }
    }

    // Reset the current position
    currentPosition.x = 0;
    currentPosition.y = 0;

    // Process Robo-Santa's route
    for (int i = 0; i < split_route / 2; i++)
    {
        char direction = robo_santa_route[i];

        switch (direction)
        {
        case '^':
            currentPosition.y += 1;
            break;
        case 'v':
            currentPosition.y -= 1;
            break;
        case '<':
            currentPosition.x -= 1;
            break;
        case '>':
            currentPosition.x += 1;
            break;
        default:
            printf("Invalid direction: %c\n", direction);
        }

        // Check if the current position has been visited
        if (!isPointVisited(visited, numVisited, currentPosition))
        {
            visited[numVisited] = currentPosition;
            numVisited++;
        }
    }

    // Free the allocated memory
    free(content);
    free(santa_route);
    free(robo_santa_route);

    printf("Number of unique stops: %d\n", numVisited);

    return 0;
}
