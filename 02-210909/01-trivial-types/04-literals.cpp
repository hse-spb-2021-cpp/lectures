#include <iostream>

int main() {
    std::cout << 12345 << "\n";
    std::cout << 1'2345 << "\n";  // C++14
    std::cout << 1'000'000'000 << "\n";  // C++14
    std::cout << 0xDEAD'BEEF << "\n";  // 0x - шестнадцатеричная система счисления
    [[maybe_unused]] int x = 0xDEAD;  // ((4 * 16 + 5) * 16 + 10) * 16 + 4
    std::cout << 067 << "\n";  // 0 - восьмеричная система счисления
    std::cout << 6 * 8 + 7 << "\n";
    std::cout << 0b11111 << "\n";  // C++14, 0b - двоичная система счисления

    // Extra reading: user-defined literals
}
