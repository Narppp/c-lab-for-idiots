
#include <stdio.h>

/*
 * This file showcases why struct padding is important and why memory alignment is
 * crucial for programs.
 */

/*
 * the size of the struct depends on how much bytes your cpu can read per cycle,
 * since my cpu can read 64 bits per cycle that just means it can read 8 bytes per
 * cycle.
 *
 * HUGE NOTE:
 * the alignment also depends on what's the biggest datatype is on the struct which
 * in this case we have a 'long' and since it's 8 bytes, the cpu has to enforce a strict
 * 8 byte alignment so the visualization looks like this:
 */
struct BadStruct {
        char random_char1; // 1 byte
        long random_long; // 8 bytes
        char random_char2; // 1 byte
        int random_int; // 4 bytes (usually)
};

/* 
 * (each block is 1 byte)
 * ======================================================================================
 * | random_char1 | padding | padding | padding | padding | padding | padding | padding |
 * ======================================================================================
 * =====================================================================================
 * | random_long | random_long | random_long | random_long | random_long | random_long |
 * =====================================================================================
 * =======================================================================================
 * | random_long | random_long | random_char2 | padding | padding | padding | random_int |
 * =======================================================================================
 * ========================================
 * | random_int | random_int | random_int |
 * ========================================
 *
 * count all that up and the output should be 24 on the terminal
 *
 *
 * now why is there padding?
 * the system does this because it can always just read that amount of bytes per cycle
 * (in this case it's 8 bytes) and this makes it so that the cpu doesn't read incomplete
 * data. It wouldn't make much sense if the cpu read 2 bytes of an int right? what 
 * could the output be if that happened?
 *
 * Now this example is actually the bad one because as you can see we padded 3 bytes
 * before the int which is inefficient and takes so much more memory than necessary.
 * to fix this, we need to properly align each datatype and order them from largest to
 * smallest so the cpu can read data efficiently.
 *
 * Let me visualize it again:
 *
 * (each block is 1 byte)
 * =====================================================================================
 * | random_long | random_long | random_long | random_long | random_long | random_long |
 * =====================================================================================
 * ===================================================================================
 * | random_long | random_long | random_int | random_int | random_int | random_int |
 * ===================================================================================
 * ===================================================
 * | random_char1 | random_char2 | padding | padding |
 * ===================================================
 */

struct GoodStruct {
        long random_long; // 8 bytes
        int random_int; // 4 bytes (usually)
        char random_char1; // 1 byte
        char random_char2; // 1 byte
};

int main(void)
{
        printf("unoptimized struct size: %zu\n", sizeof(struct BadStruct));
        printf("optimized struct size: %zu\n", sizeof(struct GoodStruct));

        /*
         * This example is extremely small but when you're building big systems, you
         * always need to keep this in mind to squeeze as much memory as you can.
         */

        return 0;
}
