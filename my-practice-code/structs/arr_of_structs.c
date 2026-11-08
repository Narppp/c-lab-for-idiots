
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 32


/* TODO:
 * Create an n amount of structs and print all the structs
 * in a table
 */
struct Students {
        char name[MAX_BUF];
        uint16_t grade;
};

void clear_buffer(void)
{
        int16_t c = 0;
        while ((c = getchar()) != '\n' && (c != EOF));
}

char *get_input(char *buffer)
{
        if (fgets(buffer, MAX_BUF, stdin) == NULL)
                exit(0);

        if (buffer[strcspn(buffer, "\n")] != '\n') {
                printf("Buffer Overflowed.\n");
                clear_buffer();
                exit(1);
        }
        buffer[strcspn(buffer, "\n")] = '\0';

        return buffer;
}

uint16_t convert_input(char *buffer)
{
        char *hold_char = NULL;
        uint16_t converted_num = (uint16_t)strtol(buffer, &hold_char, 10);

        if (hold_char == buffer || *hold_char != '\0') {
                printf("Invalid Input.\n");
                exit(1);
        }

        if (converted_num >= UINT16_MAX || converted_num <= 0) {
                printf("Invalid number.\n");
                exit(1);
        }

        return converted_num;
}

int main(void)
{
        char buffer[MAX_BUF] = {0};
        
        printf("Enter the amount of structs you want to have: ");
        get_input(buffer);

        uint16_t converted_num = convert_input(buffer);

        struct Students *user1 = malloc(converted_num * sizeof(struct Students));

        if (user1 == NULL) {
                printf("User1 malloc failed.\n");
                exit(1);
        }

        // This loops the inputs of n amount of students
        for (uint16_t idx = 0; idx < converted_num; idx++) {
                printf("Enter Student Name %d: ", idx + 1);
                get_input(user1[idx].name);

                printf("Enter the grade of student %d: ", idx + 1);
                get_input(buffer);
                user1[idx].grade = convert_input(buffer);
        }

        // This loops the info of each student and prints them out in a formatted way
        for (uint16_t snum = 0; snum < converted_num; snum++) {
                printf("\nStudent %d Name: %s\n", snum + 1, user1[snum].name);
                printf("Student %d Grade: %d\n\n", snum + 1, user1[snum].grade);
        }

        free(user1);
        return 0;
}
