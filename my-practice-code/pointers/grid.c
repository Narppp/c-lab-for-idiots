// Making Grids using Dynamic Memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define CONVERT_FAILED -1

#define MAX_BUF 32

/*
* TODO: Build a 2D Array, allocate memory for the rows and columns,
* fill it, print it, free it.
*/

void clearbuffer(void)
{
        int c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

int **free_grid(int **grid, int grid_size)
{
        for (int i = 0; i < grid_size; i++) {
                free(grid[i]);
        }

        return grid;
}

char *get_input(char *buffer
{
        while (1) {
                if (fgets(buffer, MAX_BUF, stdin) == NULL)
                        exit(1);

                if (buffer[strcspn(buffer, "\n")] != '\n') {
                        printf("Buffer Overflowed.\n");
                        clearbuffer();
                        continue;
                }
                buffer[strcspn(buffer, "\n")] = '\0';

                break;
        }

        return buffer;
}

int convert_input(char *buffer)
{
        unsigned char *holdchar = NULL;
        int convert_num = (int)strtol(buffer, &holdchar, 10);

        if (holdchar == buffer || *holdchar != '\0') {
                printf("Convertion Failed.\n");
                return CONVERT_FAILED;
        }

        if (convert_num <= 0 || convert_num > INT_MAX) {
                printf("Invalid number for allocation.\n");
                return CONVERT_FAILED;
        }

        return convert_num;
}

int **fill_grid(int **grid, int grid_size) 
{
        char buffer[MAX_BUF] = {0};
        int idx = 0;

        while (idx < grid_size) {
                printf("Enter number %d: ", idx + 1);
                get_input(buffer);

                int arr_num = convert_input(buffer);

                idx++;
        }

        return grid;
}

int main(void)
{
        char buffer[MAX_BUF] = {0};
        get_input(buffer);

        printf("Enter the number of grids you want for your array: ");
        int rows = convert_input(buffer);

        if (rows == CONVERT_FAILED) {
                exit(1);
        }

        int **grid = malloc(rows * sizeof(int *));

        if (grid == NULL) {
                printf("grid allocation failed.\n");
                exit(1);
        }

        printf("Grid allocation successful :)\n");

        for (int i = 0; i < rows; i++) {
                grid[i] = malloc(5 * sizeof(int));

                if (grid[i] == NULL) {
                        printf("column allocation failed.\n");
                        exit(1);
                }
        }

        free_grid(grid, rows);
        free(grid);

        grid = NULL;
        return 0;
}
