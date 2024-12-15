#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int numDirections;
    printf("Enter the number of directions: ");
    scanf("%d", &numDirections);

    // Array to store visited points
    Point visited[100]; // Adjust size as needed
    int numVisited = 0;

    Point currentPosition = {0, 0}; // Start at origin
    printf("Starting at: ");
    printPoint(currentPosition);

    for (int i = 0; i < numDirections; i++)
    {
        char direction;
        printf("Enter direction (U/D/L/R): ");
        scanf(" %c", &direction);

        switch (direction)
        {
        case 'U':
            currentPosition.y += 1;
            break;
        case 'D':
            currentPosition.y -= 1;
            break;
        case 'L':
            currentPosition.x -= 1;
            break;
        case 'R':
            currentPosition.x += 1;
            break;
        default:
            printf("Invalid direction!\n");
        }

        // Check if the new point is already visited
        if (!isPointVisited(visited, numVisited, currentPosition))
        {
            visited[numVisited++] = currentPosition;
            printf("New stop: ");
            printPoint(currentPosition);
        }
    }

    printf("Number of unique stops: %d\n", numVisited);

    return 0;
}
