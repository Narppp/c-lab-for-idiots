
/*
* This is my own implementation of string.h
*/

#ifndef NSTR_H
#define NSTR_H

size_t nlen(const char *str);

char *ncpy(char *restrict dest,
           const char *restrict src);

#endif
