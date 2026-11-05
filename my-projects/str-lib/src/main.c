
#include <stdio.h>
#include <nstr.h>
#include <string.h>

#define MAX_BUF 32

int main(void)
{
        char buffer1[MAX_BUF] = "hello world";
        char buffer2[MAX_BUF] = "hello world";
        char copy_buffer[] = "random string";

        char char_find = 'w';

        printf("buffer size: %zu\n", nlen(buffer1));
        
        if (ncmp(buffer1, buffer2) == 0) {
                printf("buffers are the same\n");
        } else {
                printf("buffers are not the same\n");
        }

        printf("buffer1 size: %zu\n", sizeof(buffer1));
        printf("buffer2 size: %zu\n", sizeof(buffer2));

        const char *result1 = nchr(buffer2, char_find);

        if (result1 == NULL) {
                printf("character %c not found.\n", char_find);
        } else {
                printf("character %c found in position %ld\n", char_find, result1 - buffer2);
        }

        const char *result2 = strchr(buffer2, char_find);

        if (result2 == NULL) {
                printf("character %c not found.\n", char_find);
        } else {
                printf("character %c found in position %ld\n", char_find, result2 - buffer2);
        }

        printf("buffer1 size: %zu\n", sizeof(buffer1));
        printf("buffer2 size: %zu\n", sizeof(buffer2));


        ncpy(buffer1, copy_buffer);
        printf("new buffer1: %s\n", buffer1);

        strcpy(buffer2, copy_buffer);
        printf("new buffer2: %s\n", buffer2);

        printf("buffer1 size: %zu\n", sizeof(buffer1));
        printf("buffer2 size: %zu\n", sizeof(buffer2));


        char cat_buf[] = "put this on top";

        strncpy(buffer1, cat_buf, sizeof(buffer1));
        printf("new strncpy buffer1: %s\n", buffer1);

        nncpy(buffer2, cat_buf, sizeof(buffer2));
        printf("new nncpy buffer2: %s\n", buffer2);

        strcat(buffer1, cat_buf);
        printf("new new buffer1: %s\n", buffer1);

        ncat(buffer2, cat_buf);
        printf("new new buffer2: %s\n", buffer2);

        return 0;
}
