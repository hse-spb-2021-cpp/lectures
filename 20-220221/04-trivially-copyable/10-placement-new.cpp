#include <memory>
#include <iostream>

#pragma pack(push, 1)
struct MaybeUnalignedInt {
    int value;
};
#pragma pack(pop)

int main() {
    unsigned char buf[10];
    MaybeUnalignedInt *a = reinterpret_cast<MaybeUnalignedInt*>(&buf[2]);

    // Slightly less UB, not required in C++20: http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0593r6.html
    new (a) MaybeUnalignedInt();  // placement new, <memory>

    buf[2] = 0x12;
    buf[3] = 0x34;
    buf[4] = 0x56;
    buf[5] = 0x78;
    std::cout << std::hex << a->value << "\n";

    a->~MaybeUnalignedInt();  // explicit destructor/pseudodestructor
}
