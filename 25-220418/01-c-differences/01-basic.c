#include <stdio.h>  /* All headers end with .h by convention */
/*
// is a C++-style comment, available since C99 only.

Oldest standard: C89.
GCC's default: C99. There are C11 and C17 (defects only), no C14 or C20.
Next expected standard: C23.
Language is much smaller than C++, but is not a subset.

We look at C17, but mostly C99 stuff.
I'm no specialist by any means, refer to https://www.manning.com/books/modern-c
*/

int main(void) {
    /*
    for (int i = 0; i < 10; i++) {  // Available since C99 only
    }
    */

    int i;
    for (i = 0; i < 10; i++) {
        printf("i=%d\n", i);
    }

    /* int j;  // Error in C89, but not in modern GCC. */
    {
        int j = 50;  // You can declare variables at the beginning of a block.
        printf("j=%d\n", j);
    }
}
