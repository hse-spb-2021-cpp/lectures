#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcat(char **a, const char *b) {
    char *out = malloc(strlen(*a) + strlen(b) + 1);
    out[0] = 0;

    strcpy(out, *a);
    strcpy(out + strlen(*a), b);
    free(*a);
    *a = out;
}

int main() {
    {
        // OK, but looks weird;
        char *a = malloc(6);
        strcpy(a, "hello");

        char b[] = " world";

        my_strcat(&a, b);
        // my_strcat(a + 1, b);  // UB: free in the middle of a memory
        printf("%s\n", a);
        free(a);
    }

    {
        // UB
        char a[] = "hello";
        char b[] = " world";

        char *aptr = a;
        my_strcat(&aptr, b);
        printf("%s\n", aptr);
    }
}
