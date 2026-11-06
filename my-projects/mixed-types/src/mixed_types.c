
#include "mixed_types.h"

static char *ptr_to_char = NULL;
static int32_t *ptr_to_int = NULL;
static float *ptr_to_float = NULL;
static double *ptr_to_double = NULL;

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

void print_data(struct MixedTypes *var, uint32_t size)
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
                        for(uint32_t idx = 0; idx < size; idx++) {
                                printf("Int[%d]: %d\n", idx, ptr_to_int[idx]);
                        }
                        break;
                case 'f':
                        for(uint32_t idx = 0; idx < size; idx++) {
                                printf("Float[%d]: %f\n", idx, ptr_to_float[idx]);
                        }
                        break;
                case 'd':
                        for(uint32_t idx = 0; idx < size; idx++) {
                                printf("Double[%d]: %lf\n", idx, ptr_to_double[idx]);
                        }
                        break;
        }
}

void loop_input(struct MixedTypes *var, uint32_t size)
{
        int32_t *int_arr = NULL;
        float *float_arr = NULL;
        double *double_arr = NULL;

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
                                printf("Enter Int %d: ", idx + 1);
                                get_input(var->buffer);
                                converted_num = convert_input(var->buffer);

                                int_arr[idx++] = converted_num;
                        }
                        
                        var->data = int_arr;
                        break;
                case 'f':
                        float_arr = malloc(size * sizeof(float));

                        if (float_arr == NULL) {
                                printf("Float Memory Allocation Failed.\n");
                                exit(1);
                        }

                        while (idx < size) {
                                printf("Enter Float %d: ", idx + 1);
                                get_input(var->buffer);
                                converted_num = (float)convert_input(var->buffer);

                                float_arr[idx++] = converted_num;
                        }

                        var->data = float_arr;
                        break;
                case 'd':
                        double_arr = malloc(size * sizeof(float));

                        if (double_arr == NULL) {
                                printf("Doubke Memory Allocation Failed.\n");
                                exit(1);
                        }

                        while (idx < size) {
                                printf("Enter Double %d: ", idx + 1);
                                get_input(var->buffer);
                                converted_num = (double)convert_input(var->buffer);

                                double_arr[idx++] = converted_num;
                        }

                        var->data = double_arr;
                        break;
        }
}

void check_struct_type(struct MixedTypes *var)
{
        uint32_t converted_num = 0;

        switch (var->type) {
                case 'c':
                        printf("Enter char: ");
                        get_input(var->buffer);

                        printf("char: %c\n", var->buffer[0]);
                        break;
                case 's':
                        printf("Enter String: ");
                        get_input(var->buffer);

                        printf("string: %s\n", var->buffer);
                        break;
                case 'i':
                        printf("Enter Int: ");
                        get_input(var->buffer);
                        converted_num = convert_input(var->buffer);
                        loop_input(var, converted_num);
                        print_data(var, converted_num);

                        break;
                case 'f':
                        printf("Enter Float: ");
                        get_input(var->buffer);
                        converted_num = convert_input(var->buffer);
                        loop_input(var, converted_num);
                        print_data(var, converted_num);

                        break;
                case 'd':
                        printf("Enter Double: ");
                        get_input(var->buffer);
                        converted_num = convert_input(var->buffer);
                        loop_input(var, converted_num);
                        print_data(var, converted_num);

                        break;
                default:
                        printf("Invalid type.\n");
        }
}
