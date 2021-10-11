#include <iostream>

struct Bar {
    Bar(int x) {
        std::cout << "Bar(" << x << ")\n";
    }
};

Bar &create_b1() {
    static Bar b1(10);
    return b1;
}

Bar &create_b2() {
    static Bar b2(20);
    return b2;
}
