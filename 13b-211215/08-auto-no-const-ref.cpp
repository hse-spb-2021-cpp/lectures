#include <iostream>

int val = 10;
int &foo() {
    return val;
}
const int &bar() {
    return val;
}

int main() {
    {
        [[maybe_unused]] auto x = foo();  // int
        [[maybe_unused]] auto &y = foo();  // int&
        [[maybe_unused]] const auto &z = foo();  // const int&
    }
    {
        [[maybe_unused]] auto x = bar();  // int
        [[maybe_unused]] auto &y = bar();  // const int&
        [[maybe_unused]] const auto &z = bar();  // const int&
    }
}
