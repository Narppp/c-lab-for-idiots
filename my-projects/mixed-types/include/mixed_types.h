
#ifndef MIXED_TYPES_H
#define MIXED_TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inputs.h"

#define MAX_BUF 32

struct MixedTypes {
        char buffer[MAX_BUF];
        char type;
        void *data;
};

struct MixedTypes *alloc_struct_data(void);
void print_data(struct MixedTypes *var, uint32_t size);
void loop_input(struct MixedTypes *var, uint32_t size);
void check_struct_type(struct MixedTypes *var);

#endif
