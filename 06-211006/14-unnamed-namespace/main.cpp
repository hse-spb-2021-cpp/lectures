#include <iostream>

void foo() {
    std::cout << "main foo\n";
}

void bar();

int main() {
    foo();
    bar();
}
