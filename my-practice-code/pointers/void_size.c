
#include <stdio.h>

/*
* TODO:
* - print sizeof(void *), sizeof(int *), and sizeof(char *)
* - Explain why sizeof(void) is not valid.
*/

int main(void)
{
        /*
        * This is all 8 bytes because that's the size of the pointer itself. It doesn't matter what type you point it to,
        * as long as it's a pointer it's always 8 bytes.
        */
        printf("sizeof(void *): %zu\n", sizeof(void *));
        printf("sizeof(int *): %zu\n", sizeof(int *));
        printf("sizeof(char *): %zu\n", sizeof(char *));

        /*
        * As you may have noticed at compile time, the compilation stops when it hits
        * the printf function, that's because void is just an absence of a datatype.
        * It's pretty weird to explain but the void datatype itself is an incomplete type.
        * It's not a standalone type where it has a fixed size like char, int, floats, etc. (although in some gcc versions this might put out 1).
        *
        * That's really all you need to keep in mind when using void variables, you need to castbit to something valid first before trying to get the size of it.
        */
        printf("sizeof(void): %zu\n", sizeof(void));

        return 0;
}

/*
* In this file I understood what the void datatype is and why it can never be measured staraight up.
*/
