#include <iostream>

namespace {
// internal linkage
void foo() {
    std::cout << "other foo\n";
}
}  // namespace

void bar() {
    foo();
}
