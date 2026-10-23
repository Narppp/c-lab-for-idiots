# C Lab for Idiots

I made this repo to track my current progress and learn more complex stuff in C. This repo also includes vulnerable code that you can try to fix yourself to better understand vulnerabilities in code

**NOTE:** I expect you to know a bit of C's syntax before you dive into this so you should not be confused when I use a lib or any built in functions.

## What concepts this repo could include
- Pointers
- Dynamic Memory
- Structs
- Bitwise Operators

## Vulnerabilities that may appear
- Memory Leaks - Unfreed allocations when allocating a block of memory, causing this bug.
- Heap Overflow - Caused by off-by-one pointer arithmetic.
- Stack/Buffer Overflow - Caused by not having a return call in a recursive function or the user input has more characters than the buffer size.
- Double Free/Dangling Pointers - Caused by freeing an already freed memory block or pointing to a memory block that is already freed
- Shift Overflows/Bugs - Caused by shifting bits too far to the signed bits

### Folder Structure
- 'challenge-code/' is for you to test the vulnerabilities and fix each code problem
- 'my-practice-code/' is my personal code that you can also test or break
- 'my-projects/' are the big projects that I will do with those concepts

#### clone the repo
**HTTPS**
```bash
git clone https://github.com/Narppp/c-lab-for-idiots.git
```

**SSH (recommended but needs setting up if you haven't yet)**
```bash
git clone git@github.com:Narppp/c-lab-for-idiots.git
```

## How you can compile it (my-practice-code/ and challenge-code/ directories)
- You will need a POSIX compliant environment (Linux or Unix)
- Use 'gcc' or 'clang'

change to your desired directory
```bash
cd [dir]
```

then do this command
```bash
gcc -Wall -Wextra -Werror -g -fsanitize=address,undefined -o exec/[executable_name] [filename].c
./exec/[executable_name]

or

clang -Wall -Wextra -Werror -g -fsanitize=address,undefined -o exec/[executable_name] [filename].c
./exec/[executable_name]
```

## How you can compile my projects (my-projects/ directory)

go to your desired project folder
```bash
cd [project_dir]
```

**then type 'make help'**
```bash
make help
```

- Help commands should appear when you do that, then just do the commands to build my projects easily.

have fun exploring!
