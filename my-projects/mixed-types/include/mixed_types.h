
#ifndef MIXED_TYPES_H
#define MIXED_TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "inputs.h"

struct MixedTypes {
        char buffer[MAX_BUF];
        char data_type;
        void *value;
};

struct MixedTypes *alloc_struct_data(void);
void print_data(struct MixedTypes *var);
void loop_input(struct MixedTypes *var);
void check_struct_type(struct MixedTypes *var);

#endif
