#include <iostream>
#include <memory>
#include <string>

struct Person {
    std::string first_name, last_name;
    const int id;

    Person(int id_) : first_name(10'000, 'x'), id(id_) {
        std::cout << "Person created\n";
    }
};

int main() {
    Person *buf = std::allocator<Person>().allocate(4);

    Person &a = *new (buf) Person(10);
    std::cout << a.id << std::endl;  // 10
    std::cout << buf[0].id << std::endl;  // 10? I dunno :(
    a.~Person();

    Person &b = *new (buf) Person(11);
    std::cout << &a << " " << &b << std::endl;
    std::cout << b.id << std::endl;  // ok.
    std::cout << a.id << std::endl;  // 11? UB? I dunno :(
    std::cout << buf[0].id << std::endl;  // 11? UB? I dunno :(
    std::cout << std::launder(&buf[0])->id << std::endl;  // 11. Probably not UB.
    b.~Person();

    std::allocator<Person>().deallocate(buf, 4);

    // https://wg21.link/P0532R0
}
