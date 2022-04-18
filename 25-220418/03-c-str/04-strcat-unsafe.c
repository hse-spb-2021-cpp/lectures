#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcat(char *a, const char *b) {
    size_t a_pos = strlen(a);
    for (int b_pos = 0; b[b_pos]; b_pos++) {
        printf("b_pos=%d\n", b_pos);
        a[a_pos++] = b[b_pos];
    }
    a[a_pos] = 0;
}

int main() {
    // GCC extension: you can write string literal to char* for compatibility.
    // But it's still read-only.

    /*const*/ char* a = "hello ";  // static storage duration, controlled by the compiler
    // a[0] = 'x';  // UB.
    printf("%s\n", a);

    const char* b = "world";
    // my_strcat(a, b);  // UB immediately: should not change a's content.
    // printf("%s\n", a);

    {
        char arr[] = "hello ";
        my_strcat(arr, b);  // UB: out of bounds.
        printf("%s\n", arr);
    }

    {
        char arr[11] = "hello ";
        my_strcat(arr, b);  // UB: no null-terminator. Rare, but painful
        printf("|%s|\n", arr);
        printf("%zu\n", strlen(arr));
        assert(strlen(arr) == 11);
    }
}
