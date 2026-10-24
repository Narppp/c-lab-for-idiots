
/* 
* In this file I will show you a very basic example of a use-after-free bug,
* This type of bug can occur in many different ways such as when you're pointing multiple pointers
* to the same memory block, forgetting to set pointers to NULL after freeing (dangling pointers),
* using linked lists that points to a freed node, and other more complex examples that I will tackle in this
* folder.
*
* Make sure you understand how the heap works first to better understand this concept.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX_BUF 16

/*
* TODO:
* Allocate memory for 2 pointers to point at the same time but free the allocated memory then check 
* the output to see what value it may print out.
*/

/*
* NOTE:
* if you want to get the full output without it stopping abruptly because of ASan, you can just remove
* -fsanitize=address,undefined when compiling the program.
*/


/*
* These are just regular helper functions for user inputs, you can remove them if you want and brute force tests.
*/
void clear_buffer(void)
{
        int c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

char *get_input(char *buffer)
{
        if (fgets(buffer, MAX_BUF, stdin) == NULL) {
                exit(1);
        }

        if (buffer[strcspn(buffer, "\n")] != '\n') {
                printf("Buffer Overflow.\n");
                clear_buffer();
                exit(1);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

int convert_input(char *buffer)
{
        char *hold_char = NULL;
        int converted_num = (int)strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Invalid input.\n");
                exit(1);
        }

        if (converted_num <= 0 || converted_num > INT_MAX) {
                printf("Invalid number.\n");
                exit(1);
        }

        return converted_num;
}

int main(void)
{
        char buffer[MAX_BUF] = {0};

        int *num_arr = malloc(5 * sizeof(int));
        int *point_to_num = num_arr;

        int idx = 0;

        while (idx < 5) {
                printf("Enter number %d: ", idx + 1);
                get_input(buffer);
                int num = convert_input(buffer);

                num_arr[idx] = num;

                idx++;
        }

        for (int i = 0; i < idx; i++) {
                printf("Num %d: %d\n", i + 1, point_to_num[i]);
        }

        free(num_arr);

        for (int i = 0; i < idx; i++) {
                printf("Num %d: %d\n", i + 1, point_to_num[i]);
        }

        return 0;
}

/* Once you finish experimenting and actually fixed the code (no ai bruh), you need to type what happened and how you fixed it
down here */

/* WHAT I LEARNED AND HOW I FIXED IT: */
