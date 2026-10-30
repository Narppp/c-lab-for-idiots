
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 32
#define END_OF_ARR 1

/*
 * TODO:
 * Create a array of structs that hold different types of data. Fill that array
 * of struct with the desired data, put the correct type, then convert them safely.
 */

struct MixedTypes
{
        char buffer[MAX_BUF];
        void *data;
        char type;
};

/*
 * I will create helper functions for the user inputs and struct allocation.
 * - buffer clearer
 * - input thing
 * - input converter
 * - struct allocator based on the size the user input puts
 */

struct MixedTypes *struct_alloc(void)
{
        struct MixedTypes *temp_struct = malloc(sizeof(struct MixedTypes));

        if (temp_struct == NULL) {
                printf("Struct Allocation Failed.\n");
                exit(1);
        }

        temp_struct->type = '\0';

        return temp_struct;
}

void clear_buffer(void)
{
        int c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

void menu(void)
{
        printf("--Mixed Types--\n");
        printf("1: Char\n");
        printf("2: Int\n");
        printf("3: Float\n");
        printf("4: Double\n");
        printf("5: String\n");
}

char *get_input(char *buffer)
{
        if (fgets(buffer, MAX_BUF, stdin) == NULL) {
                exit(0);
        }

        if (buffer[strcspn(buffer, "\n")] != '\n') {
                printf("Buffer Overflowed\n");
                clear_buffer();
                exit(1);
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

int convert_input(char *buffer)
{
        char *hold_char = NULL;
        int converted_num = strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Number Conversion Failed.\n");
                exit(1);
        }

        if (converted_num <= 0 || converted_num >= INT_MAX) {
                printf("Invalid Number.\n");
                exit(1);
        }

        return converted_num;
}

void loop_arr_input(struct MixedTypes *var, int arr_size)
{
        int converted_input = 0;
        int idx = 0;

        while (idx < arr_size) {
                printf("Enter number %d: ", idx + 1);
                get_input(var->buffer);
                converted_input = convert_input(var->buffer);

                data[idx++] = converted_input;
        }
        data[idx] = END_OF_ARR;
}

/*
 * Now I will create functions for the data conversion themselves.
 * - switches for type function
 * 
 */

void convert_struct_type(struct MixedTypes *struct_var)
{
        char *convertable_ptr = (char *)struct_var->data;
        int *ptr_to_int = (int *)convertable_ptr;
        // float *ptr_to_float = *(float *)convertable_ptr;
        // double *ptr_to_double = *(double *)convertable_ptr;
        int loop = 0;
        int i = 0;

        switch (struct_var->type) {
                case 'c':
                        printf("%c\n", *convertable_ptr);
                        break;
                case 's':
                        while (*convertable_ptr != '\0') {
                                printf("%c", *convertable_ptr);

                                convertable_ptr++;
                        }
                        printf("\n");

                        break;
                case 'i':
                        printf("Enter the size of your int array: ");
                        get_input(struct_var->buffer);
                        loop = convert_input(struct_var->buffer);

                        loop_arr_input(struct_var, loop);

                        while (*ptr_to_int != END_OF_ARR) {
                                printf("int arr: %d\n", ptr_to_int[i++]);
                        }
                        break;
                case 'f':
                        break;
                case 'd':
                        break;
                default:

        }
}

/*
 * this function only takes the numerical arrays only, strings and chars will not
 * be processed here.
 */

/*
 * TODO for main:
 * initialize necessary variables and make sure the code is safe.
 */
int main(void)
{
        struct MixedTypes *test_struct = struct_alloc();
        int converted_num = 0;
        
        menu();

        printf("Enter your option number: ");
        get_input(test_struct->buffer);
        converted_num = convert_input(test_struct->buffer);

        switch (converted_num) {
                case 1:
                        test_struct->type = 'c';
                        break;
                case 2:
                        test_struct->type = 'i';
                        break;
                case 3:
                        test_struct->type = 'f';
                        break;
                case 4:
                        test_struct->type = 'd';
                        break;
                case 5:
                        test_struct->type = 's';
                        break;
                default:
                        printf("invalid option number.\n");
                        exit(1);
        }

        convert_struct_type(test_struct);
        free(test_struct);
        return 0;
}
