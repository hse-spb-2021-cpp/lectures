#include <iostream>

struct Bar {
    Bar() {
        std::cout << "Bar()\n";
    }
};

Bar b;
