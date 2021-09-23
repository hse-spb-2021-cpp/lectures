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

int main() {
    {
        ratio r;
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";
        
        ratio r2{};
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        std::cout << ratio{}.num << "\n";
        std::cout << ratio().num << "\n";
    }

    {
        ratio r(10);
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";

        ratio r2{10};
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        // C++17: behavior is defined;
        // Before C++17: behavior is implementation-defined(???)
        std::cout << "a>" << ratio{10}.num << "<\n";
        std::cout << "b>" << ratio(10).num << "<\n";
    }
}
