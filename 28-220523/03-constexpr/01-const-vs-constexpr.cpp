#include <iostream>

int readInt() {
    int v;
    std::cin >> v;
    return v;
};

constexpr int sum(int a, int b) {  // is allowed to be called both in compile and run time.
    return a + b;  // Valid C++11, since C++14: more operations
}

const int N = 10;

const int X = readInt();
// constexpr int X = readInt();  // on a variable: forces compile-time const

//const int Y = sum(2, 2);
constexpr int Y = sum(2, 2);  // on a variable: forces compile-time const

int arr1[N];
// int arr2[X];
int arr3[Y];

template<int> struct Foo {};
Foo<N> foo1;
// Foo<X> foo2;
Foo<Y> foo3;

static_assert(N == 10);
// static_assert(X == 123);
static_assert(Y == 4);
static_assert(sum(3, 4) == 7);

int main() {
    std::cout << sum(readInt(), 10) << "\n";
}
