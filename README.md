# C Lab for Idiots

I made this repo to track my current progress and learn more complex stuff in C. This repo also includes vulnerable code that you can try to fix yourself to better understand vulnerabilities in code

**NOTE:** I expect you to know a bit of C's syntax before you dive into this so you should not be confused when I use a lib or any built in functions.

## What concepts this repo could include
- Pointers
- Dynamic Memory
- Structs

## Vulnerabilities that may appear
- Memory Leaks - Unfreed allocations when allocating a block of memory, causing this bug.
- Heap Overflow - Caused by off-by-one pointer arithmetic.
- Stack/Buffer Overflow - Caused by not having a return call in a recursive function or the user input has more characters than the buffer size.
- Double Free/Dangling Pointers - Caused by freeing an already freed memory block or pointing to a memory block that is already freed

## How you can compile it
- You will need a POSIX compliant environment (Linux or Unix)
- Use 'gcc' or 'clang'

change to that directory first
```bash
cd [dir]
```

then do this command
```bash
gcc -o exec/[filename] [filename].c
./exec/[filename]

or

clang -o exec/[filename] [filename].c
./exec/[filename]
```

### Folder Structure
- '/challenge-code' is for you to test the vulnerabilities and fix each code problem
- '/my-practice-code' is my personal code that you can also test or break

