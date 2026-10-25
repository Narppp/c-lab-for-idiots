
#include <dumb_vec/vector.h>

/*
* allocation of the vector itself, this determines how much memory we need to allocate for the amount of data it has.
*/
struct vector *alloc_vec(void)
{
        struct vector *test_vec = malloc(sizeof(struct vector));

        if (test_vec == NULL) {
                perror("vec alloc");
                exit(1);
        } 

        test_vec->vec_size = 0;
        test_vec->vec_cap = MEM_SIZE;
        test_vec->data = malloc(MEM_SIZE * sizeof(int));

        if (test_vec->data == NULL) {
                printf("Vector allocation failed.\n");
                exit(1);
        }

        return test_vec;
}

/*
* this function pushes a value to the vector itself and also check for reallocation if we have no space left
*/
void push_vec(struct vector *vec, int value)
{
        if (vec->vec_size > vec->vec_cap) {
                vec->vec_cap *= 2;                
                int *temp_block = realloc(vec->data, vec->vec_cap * sizeof(int));

                if (temp_block == NULL) {
                        printf("Vector memory reallocation failed.\n");
                        exit(1);
                }

                vec->data = temp_block;
        }        

        vec->data[vec->vec_size++] = value;
}

/*
* This function 'pops' values in the vector and returns it to the user, then it decrements the vec->vec_size of the struct
*/
int pop_vec(struct vector *vec)
{        
        if (vec->vec_size == 0)
                return vec->data[vec->vec_size];

        return vec->data[vec->vec_size--];
}

void free_vector(struct vector *vec)
{
        vec->vec_size = 0;
        vec->vec_cap = 0;
        vec->data = NULL;

        free(vec);
}
