#include <stdlib.h>
#include <stdio.h>

int main() {
    FILE *f = fopen("02-opaque-pointers.c", "r");  // "constructor", resources are allocated by the library.

    // Never try to access `FILE*` directly.
    char buf[20];
    fscanf(f, "%20s", buf);  // "method"
    printf("buf=|%s|\n", buf);

    fclose(f);  // "destructor"
}
