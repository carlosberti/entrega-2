#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 2048
#define COLS 208
#define NUM_ONES 51

int main()
{
    int matrix[ROWS][COLS] = {0};
    int i, j, count = 0;

    srand(time(NULL)); // seed the random number generator with the current time

    while (count < NUM_ONES)
    {
        i = rand() % ROWS;
        j = rand() % COLS;
        if (matrix[i][j] == 0)
        {
            matrix[i][j] = 1;
            count++;
        }
    }

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
