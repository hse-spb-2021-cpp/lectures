#include <iostream>

// ## and #, bad stuff happens with nested macros
// __FILE__ __LINE__
// Non-standard, but supported by (Apple) GCC, Clang, MSVC (not Intel C++): __COUNTER__, use __LINE__ instead
#define my_little_debug(x) \
    std::cout << #x << " = " << (x) \
              << " at " << __FILE__ << ":" << __LINE__ << "\n"

#define glue(a, b) a ## b
#define not_really_random (__COUNTER__ * 100)
#define new_var int var_ ## __COUNTER__  // It can be made to work! Maybe: https://stackoverflow.com/a/1295338

int main() {
    my_little_debug(2 + 2 * 2);
    my_little_debug("hello" "world");
    std::cout << __FILE__ << "\n";
    std::cout << __LINE__ << "\n";

    int xy = 123;
    std::cout << glue(x, y) << "\n";
    std::cout << not_really_random << "\n";
    std::cout << not_really_random << "\n";
    std::cout << not_really_random << "\n";

    new_var = 500;
    std::cout << var___COUNTER__ << "\n";
//    std::cout << var_3 << "\n";
//    new_var = 600;
//    std::cout << var_4 << "\n";
}
