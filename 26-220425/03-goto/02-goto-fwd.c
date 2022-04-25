#include <stdio.h>

int main(void) {
    int n = 10;
    if (n >= 5)
        goto big_n;
    int c = 100;
    printf("n is small\n");
    n += 100;
big_n:
    printf("n is big: %d; c=%d\n", n, c);
}
