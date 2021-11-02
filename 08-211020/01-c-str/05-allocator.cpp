#include <iostream>

const char *strcat(const char *a, const char *b) {
    char *res = new char[std::strlen(a) + std::strlen(b) + 1];

    int res_len = 0;
    for (int i = 0; a[i]; i++)
        res[res_len++] = a[i];
    for (int i = 0; b[i]; i++)
        res[res_len++] = b[i];
    res[res_len] = '\0';
    return res;
}

int main() {
    const char *x = "xyz";
    const char *y = strcat("xy", "z") + 1;
    // ......
    delete[] (y - 1);
}
