#include <iostream>
#include <memory>
#include <string>

struct alignas(4096) /*wtf */ Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    // std::allocator<Person> alloc;
    // Person *buf = alloc.allocate(4);
    Person *buf = std::allocator<Person>().allocate(4);
    // On Egor's machine: works with very big alignment as well.

    std::cout << sizeof(Person) << " " << alignof(Person) << std::endl;

    Person *a = new (buf) Person();
    Person *b = new (buf + 1) Person();
    Person *c = new (buf + 2) Person();
    // Person *d = new (buf + 3) Person();  // ok, but do not want right now
    std::cout << static_cast<void*>(buf) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    // Order is not important, but I prefer to minic automatic storage duration.
    c->~Person();
    b->~Person();
    a->~Person();

    // alloc.deallocate(buf, 4);
    std::allocator<Person>().deallocate(buf, 4);
}
