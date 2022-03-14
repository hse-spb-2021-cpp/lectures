#include <iostream>

template<typename T>
void print(/* const */ T &a) {
    std::cout << a << std::endl;
}

template<typename T>
void print_off(T a) {
    a++;
    std::cout << a << std::endl;
}

int main() {
    // auto &a = 10;
    // print(10);  // Arg=int. T=int. int &x;

    // auto a = 20;
    print_off(20);  // Arg=int. T=int. int x;

    const int x = 30;
    // auto &a = x;
    print(x);  // Arg=const int. T=const int. const int &x;

    // auto a = x;
    print_off(x);  // Arg=const int. T=int. int x;
}
