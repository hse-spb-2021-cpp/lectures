#include <iostream>

struct Point {
    // members
    int x, y;

    // member function
    int dist2() {  // const qualifier
        return x * x + y * y;
    }

    void operator+=(Point other) {  // operator overload
        x += other.x;
        y += other.y;
    }
};

void print(const Point &p) {
    std::cout << p.x << " " << p.y << "\n";
    // std::cout << p.dist2() << "\n";

    // WTF, use static_cast, it won't compile. Don't use const_cast, it compiles.
    Point &p2 = (Point&)(p);
    std::cout << p2.dist2() << "\n";
}

int main() {
    Point p;
    p.x = 10;
    p.y = 20;
    print(p);  // OK

    const Point const_p{30, 40};
    print(const_p);  // UB
}
