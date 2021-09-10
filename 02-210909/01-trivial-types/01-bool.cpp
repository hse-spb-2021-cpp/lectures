#include <iostream>

int main() {
    {
        bool a = 10;
        std::cout << a << "\n";
        if (a == 1) {
            std::cout << "a == 1\n";
        }
        if (a == 10) {
            std::cout << "a == 10\n";
        }
    }
    {
        std::cout << true << "\n";
        std::cout << false << "\n";
    }
    {
        bool a;
        std::cin >> a;
        std::cout << "read " << a << "\n";
    }
    std::cout << (true || true || true) << "\n";
    std::cout << 10 + true << "\n";  // int + bool ---> int + int
    std::cout << true + true + true << "\n";  // bool + bool --> int + int

    bool flag = true;
    int x = 239;
    std::cout << flag * x << "\n";

    if (x) {
        std::cout << "x != 0\n";
    } else {
        std::cout << "x = 0\n";
    }

    if ("hello") {  // 10WTF
        std::cout << "hello != 0\n";
    }
    if ("") {  // WTF
        std::cout << "empty string != 0\n";
    }
}
