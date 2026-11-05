
#include <stdio.h>

/* TODO:
 * Create a function pointer for the functions that
 * take the same arguments.
 */

void swap_value(int *a, int *b)
{
        int temp_value = *a;
        *a = *b;
        *b = temp_value;
}

void zero_values(int *a, int *b)
{
        *a = 0;
        *b = 0;
}

int main(void)
{
        /* This is how you initialize a function pointer:
         * (return type) (function pointer name) (parameters);
         *
         * As long as it has the same return type and parameters,
         * we can assign the function pointer
         * to that function.
         */
        void (*get_func)(int *,int *);
        int num1 = 5;
        int num2 = 15;
        
        get_func = &swap_value;

        printf("old num1: %d\nold num2: %d\n", num1, num2);  
        get_func(&num1, &num2);
        printf("swapped num1: %d\nswapped num2: %d\n", num1, num2);

        get_func = &zero_values;

        printf("before zero func: %d | %d\n", num1, num2);
        get_func(&num1, &num2);
        printf("after zero func: %d | %d\n", num1, num2);

        return 0;
}

/* To be honest I have no clue when I can actually use
 * this concept but I guess it's still pretty useful
 * to understand.
 */
