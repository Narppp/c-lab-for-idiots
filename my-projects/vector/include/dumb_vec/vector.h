
#ifndef VECTOR_H
#define VECTOR_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_SIZE 8

struct vector {
        int *data;
        size_t vec_size;
        size_t vec_cap;
};

struct *vector alloc_vec();
void push_vec(struct *vector, int value);
int pop_vec(struct *vector);
void free_vec(struct *vector);

#endif
