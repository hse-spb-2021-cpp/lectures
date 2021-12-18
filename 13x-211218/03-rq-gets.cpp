#include <cstdio>

int main() {
    char buf[11];
    std::gets(buf);  // Potentially UB: bufer overflow.
    std::fgets(buf, 11 /* sizeof buf */, stdin);  // No UB: it knows to not write more than 11 bytes to buf (including NULL).
}
