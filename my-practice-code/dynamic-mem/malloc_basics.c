// Dynamic Memory 1

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* TODO: Allocate and n amount to an int array at runtime. Fill the array, print the contents, and free them. Then set the pointer to NULL */
void clearBuffer(void){
  int c = 0;
  while((c = getchar()) != '\n' && (c != EOF));
}

size_t convert_input(char *buffer, size_t buffer_size){
  while(1){
    if(fgets(buffer, buffer_size, stdin) == NULL){
      exit(0);
    }

    if(buffer[strcspn(buffer, "\n")] != '\n'){
      clearBuffer();
      printf("Buffer Overflowed.\n");
      printf("Enter the size of the array: ");
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    char *holdchar = NULL;
    size_t convnum = (size_t)strtol(buffer, &holdchar, 10);

    if(holdchar == buffer || *holdchar != '\0'){
      printf("invalid input.\n");
      printf("Enter the size of the array: ");
      continue;
    }
    
    return convnum;
  }
}

size_t *get_numbers(char *buffer, size_t buffer_size, size_t arr_size, size_t *arr){
  size_t i = 0;
  while(i < arr_size){
    printf("Enter number %ld: ", i + 1);
    size_t user_num = convert_input(buffer, buffer_size);

    arr[i++] = user_num;
  }

  return arr;
}

int main(void){
  char buffer[16] = {0};

  printf("Enter the size of the array: ");
  size_t amount = convert_input(buffer, sizeof(buffer));

  size_t *arr = malloc(amount * sizeof(size_t));

  if(arr == NULL){
    printf("Memory allocation failed.\n");
    exit(1);
  }

  get_numbers(buffer, sizeof(buffer), amount, arr);

  for(size_t idx = 0; idx < amount; idx++){
    printf("Num %ld: %ld\n", idx + 1, arr[idx]);
  }

  free(arr);
  return 0;
}

/* Buggy i know but it helped me understand how to use arrays that are allocated on the heap. */
