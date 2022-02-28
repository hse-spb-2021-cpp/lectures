#include <iostream>
#include <memory>
#include <string>

struct Base {
    virtual ~Base() {}
    virtual void print();
};

struct Derived : Base {
    void print() override {
        std::cout << "Derived\n";
    }
};

void Base::print() {
    std::cout << "Base\n";

    // O_O what the phoenix
    // std::launder may or may not help
    this->~Base();
    new (this) Derived();
}

int main() {
    alignas(alignof(Derived)) unsigned char buf[sizeof(Derived)];
    static_assert(sizeof(Base) == sizeof(Derived));
    static_assert(alignof(Base) == alignof(Derived));

    Base &obj = reinterpret_cast<Base&>(buf);

    new (buf) Base();
    obj.print();
    obj.print();
    reinterpret_cast<Base&>(buf).~Base();

    new (buf) Derived();
    obj.print();  // Legal C++? I dunno.
    reinterpret_cast<Base&>(buf).~Base();

    // Another thread, did not read, but sounds fun: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86908
}
