
#include <stdio.h>

/*
* TODO:
* make a function that takes a const void datatype that points to a value and a char type of that value.
* then make a switch with cases based on that char type
*/

void print_val(const void *ptr, char type)
{
        switch (type) {
                case 'i': {
                        const int *int_ptr = (const int *)ptr;

                        printf("*int_ptr: %d\n", *int_ptr);
                        break;
                }
                case 'd': {
                        const double *double_ptr = (const double *)ptr;

                        printf("*double_ptr: %lf\n", *double_ptr);
                        break;
                }
                case 'c': {
                        const char *char_ptr = (const char *)ptr;

                        printf("*char_ptr: %c\n", *char_ptr);
                        break;
                }
                case 'f': {
                        const float *float_ptr = (const float *)ptr;

                        printf("*float_ptr: %f\n", *float_ptr);
                        break;
                }
                case 's': {
                        const char *str_ptr = (const char *)ptr;

                        while (*str_ptr != '\0') {
                                printf("%c", *str_ptr);
                                str_ptr++;
                        }
                        
                        printf("\n");
                        break;
                }
                default:
                        printf("Invalid type.\n");
        }
}

int main(void)
{
        int num = 1;
        void *ptr = &num;

        print_val(ptr, 'k');

        return 0;
}

/*
* Such an interesting project, I want to figure out how to be as type safe as I can next time because I see a lot.of vulnerabilities with this.
*/
