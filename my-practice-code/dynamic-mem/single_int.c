
#include <stdio.h>
#include <stdlib.h>

/*
* TODO:
* Allocate memory on the heap for a single integer.
* assign the value, print it, free the mem block,
* and set the pointer to NULL so it can't point to a freed memory block when we use it again.
*/

int main(void)
{
        int *ptr_to_num = malloc(sizeof(*ptr_to_num));

        /*
        * I just wanted to see the size of the dereferenced pointer and the pointer itself,
        * no need to look much into this but I know now that I allocated 1 integer on the heap
        * since int is just 4 bytes
        */
        printf("sizeof(*ptr_to_num): %lu\n", sizeof(*ptr_to_num));
        printf("sizeof(ptr_to_num): %lu\n", sizeof(ptr_to_num));

        /*
        * Literally the same as ptr_to_num[0], I just used this sinve it made more sense to me unironically.
        */
        *(ptr_to_num + 0) = 60;

        printf("ptr_to_num[0]: %d\n", *(ptr_to_num + 0));

        free(ptr_to_num);
        return 0;
}

/*
* Very simple and straightforward program, this is a good baseline to understand how malloc works and how much you
* actually use it with dynamic arrays.
*/
