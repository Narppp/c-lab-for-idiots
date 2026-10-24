
#include <dumb_vec/vector.h>

/*
* allocate this many structs to hold data
*/
struct *vector alloc_vec()
{
        *vector test_vec = malloc(sizeof(vector));

        if (test_vec == NULL) {
                perror("vec alloc");
                exit(1);
        }

        test_vec->data = NULL;
        test_vec->size = 0;
        test_vec->capacity = MEM_SIZE;

        return test_vec;
}

void push_vec(struct *vector, int value)
{
        if (vector->size == vector->capacity) {
                vector->capacity *= 2;                
                size_t temp = malloc
        }        
}

int pop_vec(struct *vector)
{

}

void free_vector(struct *vector)
{

}
