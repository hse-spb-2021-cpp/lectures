#include <iostream>

int main() {
    {
        int wtf = 123;
        std::cout << wtf << "\n";
    }
    {
        int x;
        x = x * 0;
        std::cout << x << "\n";
    }
}
