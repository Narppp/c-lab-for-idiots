// Buffer Overflow 2

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

/* In this example I will show you how we can oveflow the buffer with structs since structs are just a big just of continuous memory. 
Also watch out for sneaky bugs, I want you to fix them. */

// This struct takes the name and age of the user then determines if they're legal or not.
struct User{
  char name[64];
  int age;
  bool is_adult;
};
// Since structs are just grouped memory, you can just add the size of all members and that will be the size of the struct.
// so 64 + 4 + 1 = 69, so the entire struct should be 69 bytes right? but struct padding moves that up to 72 but this aint about structs so you should research that yourself, BUT DO KEEP THAT IN MIND.

void clearBuffer(void){
  int c = 0;
  while((c = getchar()) != '\n' && (c != EOF));
}

// Same get_input func from last time, so you should know what to do.
char *get_input(char *buffer){
  while(true){
    printf("Enter input: ");
    if(fgets(buffer, BUF_SIZE, stdin) == NULL){
      exit(0);
    }

    /* Intentionally left this out so it can break, if you want to fix it I recommend studying how strcspn works first and implementing your own fix.
    DO NOT copy the source code from the last file, you're just lying to yourself.*/

    return buffer;
  }
}

int main(void){
  struct User user1 = {0};  
  char convertion_buffer[64] = {0}; // This is only used for converting inputs.

  get_input(user1.name);

  printf("Username: %s", user1.name);

  get_input(convertion_buffer);

  /* no need to look into this, this is only for converting ther input into an integer */
  char *holdchar = NULL;
  user1.age = (int)strtol(convertion_buffer, &holdchar, 10);

  printf("Age: %d\n", user1.age);
  if(user1.age >= 18){
    user1.is_adult = true;
  }
  else{
    user1.is_adult = false;
  }

  printf("Adult: %s\n", user1.is_adult ? "true":"false");

  return 0;
}

/* Once you finish experimenting and actually fixed the code (no ai bruh), you need to type what happened and how you fixed it
down here */

/* WHAT I LEARNED AND HOW I FIXED IT: */
