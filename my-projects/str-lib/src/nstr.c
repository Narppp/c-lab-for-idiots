
#include <stdio.h>
#include <nstr.h>

size_t nlen(const char *str)
{
        size_t str_size = 0;

        while (*str != '\0') {
                str++;
                str_size++;
        }

        return str_size;
}

int ncmp(const char *str1, const char *str2)
{
        while (*str1 != '\0' && *str2 != '\0') {
                if (*str1 < *str2) {
                        return *str1 - *str2;
                } else if (*str1 > *str2) {
                        return *str1 - *str2;
                }
                str1++;
                str2++;
        }
        return *str1 - *str2;
}

char *nchr(char *restrict dest, int c)
{
        while (*dest != '\0') {
                if (*dest == c) {
                        return dest;
                }
                dest++;
        }

        return NULL;
}

char *ncpy(char *restrict dest, const char *restrict src)
{
        while (*src != '\0') {
                *dest = *src;
                
                dest++;
                src++;
        }

        *dest = '\0';

        return dest;
}

char *nncpy(char *restrict dest, const char *restrict src, size_t dest_size)
{
        size_t idx = 0;
        while (idx < dest_size && *src != '\0') {
                *dest = *src;
                dest++;
                src++;
        }

        *dest = '\0';

        return dest;
}

char *ncat(char *restrict dest, const char *restrict src)
{
        while (*dest != '\0') {
                dest++;
        }

        while (*src != '\0') {
                *dest = *src;

                dest++;
                src++;
        }
        *dest = '\0';

        return dest;
}
