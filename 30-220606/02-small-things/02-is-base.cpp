#include <type_traits>
#include <iostream>

struct SecretBase {};
struct Base {};

struct Derived : private SecretBase, public Base {
};

int main() {
    std::cout << std::is_base_of_v<Base, Derived> << "\n";  // 1
    std::cout << std::is_convertible_v<Derived*, Base*> << "\n";  // 1

    // We typically say "is a base of" when we actually mean "has pointer compatibility"
    std::cout << std::is_base_of_v<SecretBase, Derived> << "\n";  // 1
    std::cout << std::is_convertible_v<Derived*, SecretBase*> << "\n";  // 0, because inheritance is private
}
