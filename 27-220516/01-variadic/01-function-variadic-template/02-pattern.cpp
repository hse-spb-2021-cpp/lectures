#include <iostream>

void print(int a, int b, int c, int d) {
    std::cout << a << " " << b << " " << c << " " << d << "\n";
}

template<typename ...Ts>
void print_twice(const Ts &...vs) {
    print(239, vs..., 17, vs...);
}

template<typename ...Ts>
void print_plus_10(const Ts &...vs) {
    print((vs + 10)...);
}

template<typename ...Ts>
void print_double(const Ts &...vs) {
    print((vs + vs)...);  // expanded in parallel, should have the same length.
}

int main() {
    print_twice(1);
    print_plus_10(1, 2, 3, 4);
    print_double(1, 2, 3, 4);
}
