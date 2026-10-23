
#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vector {
        int data;
        size_t vec_size;
        size_t vec_cap;
};

void push_vec(struct *vector, int value);
int pop_vec(struct *vector);
void free_vec(struct *vector);

#endif
