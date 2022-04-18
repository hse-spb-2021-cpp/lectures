#include <stdio.h>
#include <string.h>

void my_strcpy(char *dest, const char *src) {
    for (int i = 0;; i++) {
        dest[i] = src[i];
        if (!src[i]) {
            return;
        }
    }
}

void run(char *foo, char *bar, char *baz) {
    my_strcpy(foo, bar);  // foo = bar
    printf("|%s|%s|\n", foo, bar);

    my_strcpy(foo, baz);
    printf("|%s|\n", foo);

    my_strcpy(foo, "12345");  // OK.
    printf("|%s|\n", foo);

    my_strcpy(foo, "123456");  // UB! But we don't know yet.
    printf("|%s|\n", foo);

    strcpy(foo, "123456");  // UB! But we don't know yet.
    printf("|%s|\n", foo);
}

int main(void) {
    char foo[] = "Hello";
    char bar[] = "World";
    char baz[] = "Hi";
    run(foo, bar, baz);
}
