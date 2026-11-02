
#include "inputs.h"

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

int32_t convert_input(char *buffer)
{
        char *hold_char = NULL;
        int32_t converted_number = strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Invalid input.\n");
                exit(1);
        }
        
        if (converted_num <= 0 || converted_num >= INT32_MAX) {
                printf("Invalid number.\n");
                exit(1);
        }

        return converted_number;
}
