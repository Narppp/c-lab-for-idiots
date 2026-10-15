// Buffer Overflow 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 64

/* In this example, I will showcase a very easy example of a buffer overflow. make sure you run the code first and try to break it
before you try to fix it to better understand how it works. */

// I will implement this clearBuffer func to automatically clear the buffer for you. you just need to call it somewhere.
void clearBuffer(void){
  int c = 0;
  while((c = getchar()) != '\n' && (c != EOF));
}

// This function will get the input of the user and when it returns to main it will print out the buffer.
char *get_input(char *buffer){
  while(1){
    printf("Enter input: ");
    if(fgets(buffer, BUF_SIZE, stdin) == NULL){
      printf("Exited program.\n");
      exit(0);
    }

    // Here we will check if the input DOESN'T have a newline, meaning we exceeded the buffer size and the newline was overwritten.
    if(buffer[strcspn(buffer, "\n")] != '\n'){
      printf("Something happened?\n"); // What happened here?
      continue;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    return buffer;
  }
}

int main(void){
  char buffer[BUF_SIZE] = {0};

  get_input(buffer);

  printf("Output: %s\n", buffer);

  return 0;
}

/* Once you finish experimenting and actually fixed the code (no ai bruh), you need to type what happened and how you fixed it
down here */

/* WHAT I LEARNED AND HOW I FIXED IT: */
