
#include <stdio.h>

/*
* TODO:
* initialize an int variable that holds a number, then initialize a void pointer that points to that variable and finally initialize a int pointer that points to the void pointer.
* Print the int pointer, then print the void pointer and void pointer + 1 and read the errors to understand.
* I will try my best to explain it myself.
*
* NOTE:
* use -Wpedantic when compiling
*/

int main(void)
{
        int num = 10;
        void *g_ptr = &num;
        int *n_ptr = g_ptr;

        /*
        * obviously we can dereference the *n_ptr variable since we explicitly said that it points to an integer, but when we do it to a void pointer it outputs an error, why?
        *
        * void pointers in C are the what's called a "generic pointer", meaning they can hold ANY value which is great, but the downside of that is we don't know what that value may be.
        * Because of that, the compiler doesn't know what we are trying to dereference, hence it outputs an error on the terminal.
        */
        printf("*n_ptr: %d\n", *n_ptr);

        /* printf("*g_ptr: %d\n", *g_ptr);
        * 
        * this is not possible because *g_ptr is a generic pointer, so it outputs a warning.
        * The possible fix is to just cast it into a datatype that is safe to dereference, usually casting it into a char * is best but because we know in this simple program that we are using ints then we can just cast it to an int * 
        */
        printf("*(int *)g_ptr: %d\n", *(int *)g_ptr);

        // (int *)g_ptr casts the g_ptr into an int so we know now that it points to an int then the most leftside pointer int *(int *)g_ptr dereferences that into whatever value g_ptr is pointing at

        int num_arr[5] = {1,2,3,4,5};
        g_ptr = num_arr;

        /* printf("*(g_ptr + 1): %d\n", *(g_ptr + 1));
        *
        * normal pointer arithmetic doesn't work with regular void pointers because we don't know how much bytes we need to jump.
        * For example we have an int array, we know that an int is 4 bytes so we need to jump 4 bytes to get to the next value but since void pointers are not
        * so to actually get the desired value we need to initialize a pointer to the same datatype as the array and cast the void pointer to that.
        */

        int *ptr_to_arr = (int *)g_ptr; // ptr_to_arr now points to the base address where g_ptr is pointing to, and we also casted it to an int *.

        for (size_t i = 0; i <= (sizeof(num_arr) / 5); i++) {
                printf("ptr_to_arr[i]: %d\n", ptr_to_arr[i]);
        }

        return 0;
}

/*
* I learned how to work with basic void pointers and how to cast them properly, now it's time for me to build more things with generic pointers and implement it to my other projects.
*/
