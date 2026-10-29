
/*
 * Pushed by dumbcoder
 */

#include <stdio.h>

#define MAX_BUF 32

/*
 * TODO:
 * Tackle all the basics of structs in C, from init styles, pointers,
 * and struct arrays
 */

struct TestStruct
{
        int data;
        char buffer[MAX_BUF];
};

void init_style(void)
{
        /*
         * There are multiple ways you can initialize a struct in C,
         * you can do positional, where you initialize each member of 
         * the struct in order like this:
         */

        struct TestStruct test1 = {99, "hello"};

        /*
         * You can also do the designated way, where you specify what
         * member you want to initialize using the .[member] syntax
         * like this:
         */

        struct TestStruct test2 = {.data = 99, .buffer = "hello"};

        /*
         * Lastly, you can just set all of the members of the struct
         * to 0, making it the safest one if you're planning to
         * use it later on instead of instantly initializing random
         * values.
         */

        struct TestStruct test3 = {0};

        printf("test1: data = %d | = %s\n", test1.data, test1.buffer); 
        printf("test1: data = %d | = %s\n", test1.data, test1.buffer);       
        printf("test1: data = %d | = %s\n\n", test1.data, test1.buffer);

}

void mov_val(struct TestStruct var)
{
        var.data = 60;
}

void mov_ptr(struct TestStruct *var)
{
        var->data = 60;
}

void init_struct_arr(struct TestStruct *var, int n)
{

        /*
         * In this function, I will set each index of the struct array's data member
         * to a random number ig
         */
        for (int i = 0; i < n; i++) {
                var[i].data = i + 10;
        }
}

int main(void)
{
        struct TestStruct testicles = {0};
        struct TestStruct arr_of_testicles[5] = {0};
        init_style();

        printf("before mov_val: .data = %d\n", testicles.data);

        /*
         * You might have noticed that after the mov_val function was called, nothing
         * happened. Why is that?
         *
         * Because functions were designed to make a COPY instead of actually editing
         * the argument you put, it won't actually change that struct, rather it
         * would just make a copy on the function's scope and when the function ends
         * the struct created inside it also dies so nothing actually happened.
         */
        mov_val(testicles);
        printf("after mov_val: .data = %d\n", testicles.data);

        printf("before mov_ptr: .data = %d\n", testicles.data);

        mov_ptr(&testicles);
        printf("after mov_ptr: .data = %d\n\n", testicles.data);

        /*
         * But here we used a pointer which actually points to the memory address where
         * the struct is located, meaning we actually did edit the struct itself even
         * if it was outside of the function's scope.
         */

        init_struct_arr(arr_of_testicles, 5);

        for (int i = 0; i < 5; i++) {
                printf("arr_of_testicles[%d].data: %d\n", i, arr_of_testicles[i].data);
        }

        return 0;
}

/*
 * In this file I understood how basic struct initialization, how pointers work alongside
 * it, and how we can work with struct arrays.
 */
