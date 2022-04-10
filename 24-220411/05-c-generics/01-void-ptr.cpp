#include <iostream>
#include <vector>

int main() {
    int a = 10;
    short b = 12345;
    std::vector<int> v{1, 2, 3};

    void *p1 = &a;  // implicit conversion: void* points to any object
    void *p2 = &b;
    void *p3 = &v;

    std::cout << p1 << "\n";
    std::cout << *static_cast<int*>(p1) << "\n";
    std::cout << *static_cast<short*>(p2) << "\n";
    std::cout << static_cast<std::vector<int>*>(p3)->size() << "\n";

    static_cast<short*>(p1);  // OK
    // *static_cast<short*>(p1);  // UB, strict aliasing violation, like reinterpret_cast<short*>(&a).

    // Impossible to know where does void* point.
}
