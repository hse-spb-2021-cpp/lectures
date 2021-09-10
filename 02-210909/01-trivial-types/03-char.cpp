#include <iostream>

int main() {
    char c = 'e';
    std::cout << c << "\n";
    std::cout << static_cast<int>(c) << "\n";
    std::cout << c - 'a' << "\n";  // char - char --> int - int --> int
    std::cout << '0' + 5 << "\n";  // char + int --> int + int --> int
    std::cout << static_cast<char>('0' + 5) << "\n";
    std::cout << static_cast<char>('0' + 10) << "\n";
    std::cout << '0' - '0' << "\n";
    std::cout << '5' - '0' << "\n";
    
    for (char c = 'a'; c <= 'z'; c++) {
        std::cout << c;
    }
    std::cout << "\n";

    for (int c = 'a'; c <= 'z'; c++) {
        std::cout << c;
    }
    std::cout << "\n";

    std::cout << static_cast<char>(49) << "\n";
    // "ASCII-код" символа: от 0 до 127

    // std::cout << 'ф' << "\n";
}
