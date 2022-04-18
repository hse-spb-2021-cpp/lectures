#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char command_line[] = "arg1 arg2 arg3";
    // strtok does something like this
    for (int i = 0; command_line[i]; i++) {
        if (command_line[i] == ' ') {
            command_line[i] = 0;
        }
    }

    // Linux may parse command line arguments like this.
    char* tokens[] = {
        command_line + 0,
        command_line + 5,
        command_line + 10,
    };
    printf("%s\n", tokens[0]);
    printf("%s\n", tokens[1]);
    printf("%s\n", tokens[2]);

    printf("argc=%d\n", argc);
    for (int i = 0; i < argc; i++) {
        // %s is 'string', %p is 'pointer'.
        // %zu is 'size_t'.
        printf("argv[]=%s, strlen=%zu, p=%p\n", argv[i], strlen(argv[i]), argv[i]);
        printf("len=%zu\n", sizeof(argv[i]));  // Never do this, it's just sizeof(char*)
    }
}
