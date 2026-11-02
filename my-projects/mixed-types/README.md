# Mixed Types in C

- This project focuses on void pointers and how to properly
cast and dereference them. I still have not figured out how
I can safely do this nor fully understand it but this is
the best attempt I can do with it.

## Stuff inside

```C
struct MixedTypes {
    char buffer[MAX_BUF];
    char type;
    void *data; // random value goes here
}
```

- User types a specific type they want to use (char, int,
str, double, float)
- We use a separate variable to store that value and point
the void pointer variable there
- Identify what datatype is it based on the type member on
the struct
- Safely cast it to that type and show the value/values to
the user

## What I have not figured out yet

- What if they chose a wrong type?
- Why use this? (need to scale to understand properly)
- How to make this more efficient?

**This is originally on the 'my-practice-code/pointers/'
but I removed it due to it being unexpectedly complicated**
