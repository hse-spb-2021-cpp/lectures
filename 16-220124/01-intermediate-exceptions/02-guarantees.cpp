#include <cassert>
#include <iostream>
#include <vector>
#include <stdexcept>

void do_something() {
    // throw std::bad_alloc();  // Uncomment when running under Valgrind/ASan, it does not like not having enough memory and will close instead of bad_alloc.
    std::vector<int> vec(100'000'000'000);
    vec[vec.size() - 1] = 123;
}

void no_guarantee() {
    std::cout << "2+2=";
    int *data = new int[10];
    do_something();
    delete[] data;
    std::cout << "4\n";
}

void basic_guarantee_1() {
    std::cout << "2+2=\n";
    std::vector<int> data(10);
    do_something();
    std::cout << "4\n";
}

void basic_guarantee_2() {
    std::cout << "2+2=4\n";
    std::vector<int> data(10);
    do_something();
}

void strong_guarantee() {
    std::vector<int> data(10);
    do_something();
    std::cout << "2+2=4\n";
}

void noexcept_guarantee() noexcept {
    assert(std::cout.exceptions() == std::ios_base::goodbit);
    std::cout << "2+2=4\n";
}

int main() {
    try {
        switch (0) {
        case 0: no_guarantee(); break;
        case 1: basic_guarantee_1(); break;
        case 2: basic_guarantee_2(); break;
        case 3: strong_guarantee(); break;
        case 4: noexcept_guarantee(); break;
        }
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
