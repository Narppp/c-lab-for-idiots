
#include "inputs.h"

void menu(void)
{
        printf("c: Char\n");
        printf("s: String\n");
        printf("i: Int\n");
        printf("f: Float\n");
        printf("d: Double\n");
}

void clear_buffer(void)
{
        int c = 0;
        while((c = getchar()) != '\n' && (c != EOF));
}

char *get_input(char *buffer)
{
        if (fgets(buffer, MAX_BUF, stdin) == NULL) {
                exit(0);
        }

        if (buffer[strcspn(buffer, "\n")] != '\n') {
                clear_buffer();
                printf("Buffer Overflowed.\n");
                exit(1);
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

/*
 * convert_input function converts unsigned ints only, so these are the use cases of it:
 * - option number converter
 * - array size converter
 */
int32_t convert_input(char *buffer)
{
        char *hold_char = NULL;
        int32_t converted_number = strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Invalid input.\n");
                exit(1);
        }
        
        if (converted_number <= 0 || converted_number >= INT32_MAX) {
                printf("Invalid number.\n");
                exit(1);
        }

        return converted_number;
}
