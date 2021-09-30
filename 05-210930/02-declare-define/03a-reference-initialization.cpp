#include <iostream>

int main() {
    int x = 10;
    int &y = x;  // reference initialization: '&' is part of a type

    std::cout << x << " " << y << "\n";  // 10 10
    x++;
    std::cout << x << " " << y << "\n";  // 11 11
    y++;
    std::cout << x << " " << y << "\n";  // 12 12
    
    // Also:
    // (2 & 3) - bitwise AND
    // (true && false) - logical AND
    // No connection whatsoever.

    // Careful: not to confuse with pointers!
    int *z = &x;  // copy initialization; '&' is unary operator
    int x2 = 100;

    std::cout << *z << "\n";  // x == 12
    *z = 10;  // x = 10
    std::cout << x << " " << y << " " << *z << "\n";  // 10 10 10

    z = &x2;

    std::cout << *z << "\n";  // x2 == 100
    *z = 200;  // x2 = 200
    std::cout << x << " " << y << " " << *z << "\n";  // 10 10 200
}
