
#ifndef INPUTS_H
#define INPUTS_H

#include "mixed_types.h"

#define MAX_BUF 32
#define END_OF_ARR 1

void clear_buffer(void);
char *get_input(char *buffer);
int32_t convert_input(char *buffer);

#endif
