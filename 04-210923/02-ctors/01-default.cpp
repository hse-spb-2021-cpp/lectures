#include <iostream>

struct ratio {
    int num;
    int denom;
    ratio() {
        num = 0;
        denom = 1;
        std::cout << "Constructing!\n";
    }
};

int main() {
    ratio r;
    std::cout << r.num << "\n";
    std::cout << r.denom << "\n";
    std::cout << ratio{}.num << "\n";  // Not UB, ok even in C++03.
}
