
#include "mixed_types.h"

static char *ptr_to_char = NULL;
static int32_t *ptr_to_int = NULL;
static float *ptr_to_float = NULL;
static double *ptr_to_double = NULL;

static uint32_t idx = 0;

struct MixedTypes *alloc_struct_data(void)
{
        struct MixedTypes *test_struct = malloc(sizeof(struct MixedTypes));
        
        if (test_struct == NULL) {
                printf("Struct Memory Allocation Failed.\n");
                exit(1);
        }

        test_struct->type = '\0';
        return test_struct;
}

void print_data(struct MixedTypes *var)
{
        ptr_to_char = (char *)var->data;
        ptr_to_int = (int32_t *)var->data;
        ptr_to_float = (float *)var->data;
        ptr_to_double = (double *)var->data;

        switch (var->type) {
                case 'c':
                        printf("Char: %c\n", *ptr_to_char);
                        break;
                case 's':
                        printf("Str: %s\n", ptr_to_char);
                        break;
                case 'i':
                        while (*ptr_to_int != END_OF_ARR) {
                                printf("Int[%d]: %d\n", idx + 1, *ptr_to_int);
                                ptr_to_int++;
                        }
                        idx = 0;

                        break;
                case 'f':
                        while (*ptr_to_float != END_OF_ARR) {
                                printf("Float[%d]: %.2f\n", idx + 1, *ptr_to_float);
                                ptr_to_float++;
                        }
                        idx = 0;

                        break;
                case 'd':
                        while (*ptr_to_double != END_OF_ARR) {
                                printf("Float[%d]: %.2f\n", idx + 1, *ptr_to_double);
                                ptr_to_double++;
                        }
                        idx = 0;

                        break;
        }
}

void loop_input(struct MixedTypes *var, uint32_t size)
{
        int32_t *int_arr = NULL;
        float *float_arr = NULL;
        // double *double_arr = NULL;

        uint32_t idx = 0;
        uint32_t converted_num = 0;

        switch (var->type) {
                case 'i':
                        int_arr = malloc(size * sizeof(int32_t));

                        if (int_arr == NULL) {
                                printf("Int Array Memory Allocation Failed.\n");
                                exit(1);
                        }

                        while (idx < size) {
                                printf("Enter Int %d: ", idx);
                                get_input(var->buffer);
                                converted_num = convert_input(var->buffer);

                                int_arr[idx++] = converted_num;
                        }
                        int_arr[idx] = END_OF_ARR;
                        
                        var->data = int_arr;
                        break;
                case 'f':
                        float_arr = malloc(size * sizeof(float));

                        if (float_arr == NULL) {
                                printf("Float Memory Allocation Failed.\n");
                                exit(1);
                        }

                        while (idx < size) {
                                printf("Enter Float %d: ", idx);
                                get_input(var->buffer);
                                converted_num = (float)convert_input(var->buffer);

                                float_arr[idx++] = converted_num;
                        }

                        var->data = float_arr;
                        break;
                case 'd':
        }
}

void check_struct_type(struct MixedTypes *var)
{
        switch (var->type) {
                case 'c':
                        printf("Enter char: ");
                        get_input(var->buffer);

                        printf("char: %c\n", var->buffer[0]);
                        break;
                case 's':
                case 'i':
                case 'f':
                case 'd':
                default:
                        printf("Invalid type.\n");
        }
}
