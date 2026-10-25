
#ifndef INPUTS_H
#define INPUTS_H

#include <dumb_vec/vector.h>

#define MAX_BUF 16

void menu(void);
void clear_buffer(void);
char *get_input(char *buffer);
int convert_input(struct vector *vec, char *buffer);

#endif
