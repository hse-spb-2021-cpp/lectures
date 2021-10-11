#include <iostream>

struct Bar {
    Bar(int x) {
        std::cout << "Bar(" << x << ")\n";
    }
};

Bar b1(10);
Bar b2(20);
