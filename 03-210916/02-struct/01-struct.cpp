#include <iostream>

struct Point {
    // members
    int x, y;

    // member function
    int dist2() {
        return x * x + y * y;
    }

    void operator+=(Point other) {  // operator overload
        x += other.x;
        y += other.y;
        // z = 10;
    }
};

void foo([[maybe_unused]] Point p) {
}

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    std::cout << p.x << " " << p.y << "\n";
    std::cout << p.dist2() << "\n";

    p += {5, 5};
    // p.operator+=(Point{5, 5});
    std::cout << p.x << " " << p.y << "\n";

    Point p2{30, 40};
    std::cout << p2.x << " " << p2.y << "\n";

    auto [x, y] = p2;
    std::cout << x << " " << y << "\n";
}
