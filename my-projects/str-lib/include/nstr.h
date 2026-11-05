
#ifndef NSTR_H
#define NSTR_H

// strlen
size_t nlen(const char *str);

// strcmp
int ncmp(const char *str1, const char *str2);

// strchr
char *nchr(char *str, int c);

// strcpy/strncpy
char *ncpy(char *restrict dest, const char *restrict src);
char *nncpy(char *restrict dest, const char *restrict src, size_t dest_size);

// strcat
char *ncat(char *restrict dest, const char *restrict src);

#endif
