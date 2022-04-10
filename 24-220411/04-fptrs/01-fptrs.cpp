#include <iostream>

void apply(void (*operation)(int)) { // cdecl.org
    std::cout << "calling with 10\n";
    operation(10);
}

using ApplyArgument = void(*)(int);
void apply2(ApplyArgument operation) { // cdecl.org
    std::cout << "calling with 10\n";
    operation(10);
}

template<typename T>
void print(T x) {
    std::cout << x << "\n";
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

int main() {
   apply(print);
   apply(print_twice);
   apply2(print);
   apply2(print_twice);
}
