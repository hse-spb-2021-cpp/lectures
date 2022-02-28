#include <iostream>
#include <memory>
#include <string>

struct /* alignas(256) wtf */ Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    unsigned char *buf = new unsigned char[sizeof(Person) * 4];
    // Alignment: ok for all 'adequate' types (for some definition of 'adequate').

    // new Person[4];
    std::cout << sizeof(Person) << " " << alignof(Person) << std::endl;

    Person *a = new (buf) Person();
    Person *b = new (buf + sizeof(Person)) Person();
    Person *c = new (buf + 2 * sizeof(Person)) Person();
    // Person *d = new (buf + 3 * sizeof(Person)) Person();  // ok, but do not want right now
    std::cout << static_cast<void*>(buf) << " " << a << " " << b << " " << c << std::endl;
    std::cout << a->first_name.size() << std::endl;

    // Order is not important, but I prefer to minic automatic storage duration.
    c->~Person();
    b->~Person();
    a->~Person();

    delete[] buf;
}
