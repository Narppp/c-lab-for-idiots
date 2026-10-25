
#include <dumb_vec/inputs.h>
#include <dumb_vec/vector.h>

void menu(void)
{
        printf("1: Push\n");
        printf("2: Pop\n");
        printf("3: Exit\n");

        fflush(stdout);
}

void clear_buffer(void)
{
        int c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

char *get_input(char *buffer)
{
        if (fgets(buffer, MAX_BUF, stdin) == NULL) {
                exit(1);
        }
        
        if (buffer[strcspn(buffer, "\n")] != '\n') {
                printf("Buffer Overflowed.\n");
                clear_buffer();
                exit(1);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

int convert_input(struct vector *vec, char *buffer)
{
        char *hold_chars = NULL;
        vec->data[vec->vec_size] = (int)strtol(buffer, &hold_chars, 10);

        if (hold_chars == buffer || *hold_chars != '\0') {
                printf("Invalid input.\n");
                exit(1);
        }

        if (vec->data[vec->vec_size] <= 0 || vec->data[vec->vec_size] > INT_MAX) {
                printf("Invalid number.\n");
                exit(1);
        }

        return vec->data[vec->vec_size];
}
