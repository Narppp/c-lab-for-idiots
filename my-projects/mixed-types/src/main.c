
#include "inputs.h"
#include "mixed_types.h"

/*
 * Main function, what do we do?:
 * - allocate memory for the struct ✓
 * - get the data type the user wants first ✓
 * - check if valid type ✓
 * - get input for that specific type ✓
 * - print the output ✓
 * - exit safely ✓
 */
int main(void)
{
        struct MixedTypes *main_struct = alloc_struct_data();
        
        menu();
        printf("Enter the type you want to use: ");
        get_input(main_struct->buffer);
        main_struct->type = main_struct->buffer[0];

        check_struct_type(main_struct);
        return 0;
}
