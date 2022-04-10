#include <cassert>

void func() {}

int main() {
    // Technically incorrect: functions are not objects, but used in Linux a lot
    void *pfunc = static_cast<void*>(func);

    int buf[10];
    void *ptr = buf;
    void *ptr2 = ptr + 5;  // GCC extension! -pedantic only emits warning, see -pedantic-errors
    assert(ptr2 == static_cast<char*>(ptr) + 5);
}
