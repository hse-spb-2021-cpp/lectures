#include <iostream>
#include "a.h"

int main() {
    std::cout << "From main()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
    std::cout << var3 << " " << &var3 << "\n";
    foo();
}
