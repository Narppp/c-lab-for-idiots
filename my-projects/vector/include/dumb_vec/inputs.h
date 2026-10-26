
#ifndef INPUTS_H
#define INPUTS_H

#include <dumb_vec/vector.h>

#define MAX_BUF 16

struct user {
        char buffer[MAX_BUF];
        int option_num;
};

void menu(struct vector *vec);
void clear_buffer(void);
char *get_input(char *buffer);
int convert_vec_data(char *buffer);

#endif
