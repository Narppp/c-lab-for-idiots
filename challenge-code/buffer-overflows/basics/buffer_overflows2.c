// Buffer Overflow 2

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 64

/* In this example I will show you how we can oveflow the buffer with structs since structs are just a big just of continuous memory. */

// This struct takes the name and age of the user then determines if they're legal or not.
struct User{
  char name[BUF_SIZE];
  int age;
  bool is_adult;
};
// Since structs are just grouped memory, you can just add the size of all members and that will be the size of the struct.
// so 64 + 4 + 1 = 69, so the entire struct size is 69 bytes, KEEP THAT IN MIND.

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

  get_input(user1.name);

  printf("Username: %s\n", user1.name);
  printf("Age: %d\n", user1.age);
  printf("Adult: %b\n", user1.is_adult);

  return 0;
}
