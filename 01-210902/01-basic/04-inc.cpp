#include <iostream>
int main() {
    {
        int x = 0;
        x = x + 10;
        x += 10;

        x = x + 1;
        x += 1;
        x++;
        ++x;
    }
    {
        int x = 10;
        int y = x += 20;  // x += 20; y = x;
        std::cout << y << "\n";
        // x = 30
        int z1 = x++;  // z1 = x (30); x++; 
        int z2 = ++x;  // ++x; z2 = x (32);
        std::cout << z1 << " " << z2 << "\n";

//        int z3 = x++ + --x; // UB
//        std::cout << z3 << "\n";

        x += z1 += 10;
        std::cout << z1 << "\n";  // 40
        std::cout << x << "\n";  // 72
    }
}
