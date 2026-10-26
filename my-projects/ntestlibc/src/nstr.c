
#include <nlib/nstr.h>

size_t nlen(const char *str)
{
        size_t length = 0;

        while (*str != '\0') {
                str++
                length++
        }

        return length;
}

char *ncpy()
