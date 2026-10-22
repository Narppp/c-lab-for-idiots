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

void clear_buffer(void)
{
        int c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

/*
* NOTE TO SELF:
* this function allocates columns for each row on the grid, this depends in how many the user wants.
*/
int **alloc_columns(int **grid, int rows, int column_amount)
{
        for (int idx = 0; idx < rows; idx++) {
                grid[idx] = malloc(column_amount * sizeof(int));
        }

        return grid;
}

void free_entire_grid(int **grid, int grid_size)
{
        for (int i = 0; i < grid_size; i++) {
                free(grid[i]);
        }

        free(grid);
}

char *get_input(char *buffer)
{
        while (1) {
                if (fgets(buffer, MAX_BUF, stdin) == NULL)
                        exit(1);

                if (buffer[strcspn(buffer, "\n")] != '\n') {
                        printf("Buffer Overflowed.\n");
                        clear_buffer();
                        continue;
                }
                buffer[strcspn(buffer, "\n")] = '\0';

                break;
        }

        return buffer;
}

int convert_input(char *buffer)
{
        char *hold_char = NULL;
        int convert_num = (int)strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Convertion Failed.\n");
                return CONVERT_FAILED;
        }

        if (convert_num <= 0 || convert_num > INT_MAX) {
                printf("Invalid number for allocation.\n");
                return CONVERT_FAILED;
        }

        return convert_num;
}

int **fill_columns(int **grid, int rows, int column_amount) 
{
        char buffer[MAX_BUF] = {0};
        int idx = 0;
        int column_count = 0;

        while (idx < rows) {

                if (column_count == column_amount) {
                        column_count = 0;
                        idx++;
                }

                printf("Enter number %d in column %d: ", column_count + 1, idx + 1);
                get_input(buffer);

                int arr_num = convert_input(buffer);

                grid[idx][column_count] = arr_num;

                if (grid[idx][column_count] == CONVERT_FAILED) {
                        exit(1);
                }

                column_count++;
        }

        return grid;
}

int main(void)
{
        char buffer[MAX_BUF] = {0};
        printf("Enter the number of grids you want for your array: ");
        get_input(buffer);

        int rows = convert_input(buffer);

        if (rows == CONVERT_FAILED) {
                exit(1);
        } 

        int **grid = malloc(rows * sizeof(int *));

        if (grid == NULL) {
                printf("grid allocation failed.\n");
                exit(1);
        }

        printf("Enter the amount of columns inside your grids: ");
        get_input(buffer);

        int columns = convert_input(buffer);

        if (columns == CONVERT_FAILED) {
                exit(1);
        }

        alloc_columns(grid, rows, columns);
        fill_columns(grid, rows, columns);

        free_entire_grid(grid, rows);
        grid = NULL;

        return 0;
}
