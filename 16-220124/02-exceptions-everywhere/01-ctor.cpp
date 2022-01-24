#include <iostream>

template<int X, bool SHOULD_THROW = false>
struct with_destructor {
    with_destructor(bool should_throw = false) {
        std::cout << "constructing " << X << "\n";
        if (SHOULD_THROW || should_throw) {
            throw 0;
        }
    }
    ~with_destructor() {
        std::cout << "destructing " << X << "\n";
    }
};

int main() {
    try {
        with_destructor<0> x;
        with_destructor<1> y(true);
//        with_destructor<1, true> y;
        with_destructor<2> z;
    } catch (...) {
        std::cout << "Caught\n";
    }
}
