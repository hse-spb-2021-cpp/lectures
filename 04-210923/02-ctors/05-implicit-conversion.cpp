#include <iostream>

struct ratio {
    int num;
    int denom;
    ratio() {
        num = 0;
        denom = 1;
        std::cout << "Default constructor\n";
    }
    ratio(int value) {
        num = value;
        denom = 1;
        std::cout << "ratio(int)\n";
    }
};

void println(const ratio &r) {
    std::cout << r.num << " " << r.denom << "\n";
}

ratio generate_ratio() {
    return 123;
}

int main() {
    ratio r = 10;
    println(r);
    println(10);
    println(generate_ratio());
}
