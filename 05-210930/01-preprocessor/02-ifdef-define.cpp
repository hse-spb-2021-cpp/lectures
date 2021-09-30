#include <iostream>

#define SOME_VAR
// CMakeLists.txt: add_compile_flags(main -DSOME_VAR)
// #define SOME_VALUE 123
#define SOME_VALUE 123 + 1

int main() {
    #ifdef SOME_VAR
    std::cout << "SOME_VAR was defined\n";
    // #warning Some var is defined!
    // #error "Some var is defined, please don't!"
    #else
    std::cout << "SOME_VAR was not defined\n";
    #endif

    #if defined(SOME_VAR) && 1 >= 2
    std::cout << "x\n";
    #endif

    #ifdef __cplusplus
    std::cout << "We are C++\n";
    #else
    std::cout << "We are not C++???\n";
    #endif

    #if __cplusplus >= 201700L
    std::cout << "C++17\n";
    #elif __cplusplus >= 201400L
    std::cout << "C++14\n";
    #endif

    std::cout << SOME_VALUE * 100 << "\n";
}
