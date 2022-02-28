#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    Person *buf = std::allocator<Person>().allocate(4);

    Person *a = new (buf) Person();
    Person *b = new (buf + 1) Person();
    Person *c = new (buf + 2) Person();  // Technically UB in C++17 and prior. Fixed in C++20: P0593R6, http://www.open-std.org/jtc1/sc22/wg21/docs/cwg_active.html#2182
    // Do not try placement new of arrays: https://github.com/Nekrolm/ubbook/blob/master/pointer_prominence/array_placement_new.md
    std::cout << static_cast<void*>(buf) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    c->~Person();
    b->~Person();
    a->~Person();

    std::allocator<Person>().deallocate(buf, 4);
}
