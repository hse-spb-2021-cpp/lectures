void print_hello(int = 10);  // UB: differs from print_hello.cpp, several definitions of the default parameter (ODR-violation).

int main() {
    print_hello();
}
