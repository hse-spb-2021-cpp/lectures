#include <iostream>
#include <iomanip>
#include <cstddef>
// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    int field = 100;
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived1 : virtual Base {
    void foo() override {
    }
};

struct Derived2 : virtual Base {
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
};

int main() {
    DerivedX a;
    a.foo();

    // Комментарии дальше специфичны для машины Егора.
    // У вас могут быть абсолютно другие результаты.

    std::cout << sizeof(Base) << "\n";  // 16: vptr (8), int (4), padding (4)
    std::cout << sizeof(Derived1) << "\n";  // 8+16: ptr-to-Base (8) | Base (16)
    std::cout << sizeof(Derived2) << "\n";  // 8+16: ptr-to-Base (8) | Base (16)
    std::cout << sizeof(DerivedX) << "\n";  // 16+16: Derived1 (8),  Derived2 (8) | Base (16)

    std::cout << &static_cast<Base&>(a) << "\n";  // X+0x10
    std::cout << &static_cast<Derived1&>(a) << "\n";  // X+0x00
    std::cout << &static_cast<Derived2&>(a) << "\n";  // X+0x08
    std::cout << &a << "\n";  // X+0x00

    /*
    У Егора (msys2 mingw-w64-x86_64) выводится:
    0xf50f9c0
    0xf50f9b0
    0xf50f9b8
    0xf50f9b0
    // К сожалению, непонятно, что это за указатели. Возможно, относительные?
    d8 46 e7 3f // Derived 1
    01 00 00 00
    f8 46 e7 3f // Derived 2
    01 00 00 00
    20 47 e7 3f // Base
    01 00 00 00
    64 00 00 00 // Base::field
    00 00 00 00
    */
    std::cout << std::hex;
    for (std::size_t i = 0; i < sizeof(DerivedX); i++) {
        char *ptr = reinterpret_cast<char*>(&a) + i;
        std::cout << std::setfill('0') << std::setw(2) << (static_cast<int>(*ptr) & 0xFF) << " ";
        if (i % 4 == 3) {
            std::cout << "\n";
        }
    }
}
