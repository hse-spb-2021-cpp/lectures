#include <stdio.h>

int main() {
    printf("> ");

    char command[10];
    gets(command);  // Buffer-overflow
    // Top-1 vulnerability: https://ulearn.me/course/hackerdom/Perepolnenie_steka_3bda1c2c-c2a1-4fb0-9146-fccc47daf93b

    printf("command is |%s|\n", command);
}
