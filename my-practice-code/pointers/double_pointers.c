// Double Pointers in C

#include <stdio.h>
#include <stdlib.h>

/* TODO: Make a helper function allocate memory on the spot and return to main,
* ensuring the pointer points to that block on the heap. */

/*
* We use a double pointer here to point the argument to that memory block directly
* in a helper function, no need to go to main to do it there. 
* Inside the function, we dereference it once to allocate that much memory
* inside the int array, and when we return to main the arr parameter
* is pointed to that memory on the heap. 
*/
void alloc_int(int **arr)
{
        *arr = malloc(5 * sizeof(int));

        if(arr == NULL){
                printf("Bad mem allocation.\n");
                exit(1);
        }
}

int *fill_arr(int *arr, 
              size_t arr_size)
{
        for(size_t i = 0; i < arr_size; i++){
                arr[i] = i * 10;
        }

        return arr;
}

int main(void)
{
        int *num_arr = NULL;
        alloc_int(&num_arr);
        fill_arr(num_arr, 5);

        for(int i = 0; i < 5; i++){
                printf("%d: %d\n", i + 1, num_arr[i]);
        }

        free(num_arr);
        return 0;
}

/* 
* In this lesson I understood that I can use a helper function to allocate memory there directly instead
* of allocating everything on main. I do not know if this will become useful.in the future but it's a neat little trick. 
*/


/* 
* sorry for the indentation, I am slowly applying the linux coding style in my code
* because it is my dream to contribute there. From now on this is how I will write code.
*/
