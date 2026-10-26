
#include <dumb_vec/inputs.h>
#include <dumb_vec/vector.h>

int main(void)
{
        struct user user_input = {0};
        struct vector *vec = alloc_vec();

        int converted_data_value = 0;
        int popped_value = 0;

        while (user_input.option_num != 3) {
                menu(vec);
                printf("Enter your option number: ");
                get_input(user_input.buffer);
                user_input.option_num = convert_vec_data(user_input.buffer);

                switch (user_input.option_num) {
                        case 1:
                                printf("Enter the number you want to add to your vector: ");
                                get_input(vec->buffer);

                                converted_data_value = convert_vec_data(vec->buffer);
                                
                                push_vec(vec, converted_data_value); 
                                break;
                        case 2:                                
                                popped_value = pop_vec(vec);

                                if (vec->data[vec->vec_size] == EMPTY_VECTOR) {
                                        printf("Vector is empty, cannot pop value.\n");
                                        break;
                                }

                                printf("Popped value: %d\n", popped_value);
                                break;
                }
        }

        free_vector(vec);
        return 0;
}

/*
* Finally done, not as hard as I thought but this is a really fun project nonetheless.
* This still has integer overflow bugs so putting an insanely high number would put out weird behaviour,
* other than that this should be pretty decent.
*/
