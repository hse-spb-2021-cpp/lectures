#include <stdio.h>

int main() {
    printf("> ");

    char command[10];
    // Мы за безопасный gets!
    fgets(command, sizeof command, stdin);  // Always null-terminated string, truncated.

    // C++'s string never truncates, but may exhaust whole memory.

    printf("command is |%s|\n", command);
}
