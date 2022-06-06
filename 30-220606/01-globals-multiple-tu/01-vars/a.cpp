#include "a.h"
#include <iostream>

int var1 = 10;
std::string var2 = "hello";

void foo() {
    std::cout << "From foo()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
}
