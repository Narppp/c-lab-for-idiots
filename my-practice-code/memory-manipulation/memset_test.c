
#include <stdio.h>
#include <string.h>

/*
* TODO:
* Use memset to set an array to 0 and 1, then explain why the output of 1 is 16843009
*/
int main(void)
{
        int num_arr[5] = {2,3,5,6,7};

        for (int i = 0; i < 5; i++) {
                printf("Num %d: %d\n", i + 1, num_arr[i]);
        }
        printf("\n");

        /*
        * When we use memset, we are setting each BYTE in a hexadecimal representation
        * into that specific number. so when we set an integer to 0 (4 bytes), it looks like this:
        *
        * ----> [00] [00] [00] [00]
        *  
        * Those separated zeros are a byte long (since hex splits each byte into 4 bits).
        * But this is an easy example, what if we set it to 1?
        */
        memset(num_arr, 0, sizeof(num_arr));

        for (int i = 0; i < 5; i++) {
                printf("Num %d: %d\n", i + 1, num_arr[i]);
        }
        printf("\n");

        /*
        * At runtime, you might see a weird number popping up on the last iteration,
        * this number is 16843009 but why is that?
        *
        * when I told earlier that memset works byte per byte, it looks like this in binary:
        *
        * ----> 00000001 00000001 00000001 00000001
        *
        *  and since we split hex into 4 bits when we convert it, now it will look like this:
        *
        *  ----> 0000 0001 | 0000 0001 | 0000 0001 | 0000 0001
        *
        *  now it make so much more sense right? when you convert all of this in hex it's just this:
        *
        *  ----> 01 01 01 01
        *
        *  if you want to see it in that representstion just use the format specifier %08x
        */
        memset(num_arr, 1, sizeof(num_arr));

        for (int i = 0; i < 5; i++) {
                printf("Num %d: %d\n", i + 1, num_arr[i]);
        }

        /*
        * Why is the number 16843009 then?
        * go back to the binary representation and try to convert this into decimal:
        *
        * ----> 00000001 00000001 00000001 00000001
        *
        *  Answer:
        */

        return 0;
}

/*
* I understood how memset works now under the hood, it's a great function for generally setting
* values to 0, I just used an example where 1 can be used.
*/
