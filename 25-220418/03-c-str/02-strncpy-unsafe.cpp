#include <stdio.h>
#include <string.h>

void my_strncpy(char *dest, const char *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
        if (!src[i]) {
            return;
        }
    }
}

int main() {
    char foo[] = "Hello";
    my_strncpy(foo, "123456", sizeof foo);  // ok, yet.
    printf("%s\n", foo);  // UB! Not null-terminated.

    strncpy(foo, "123456", sizeof foo);  // ok, yet.
    printf("%s\n", foo);  // UB! Not null-terminated.
}
