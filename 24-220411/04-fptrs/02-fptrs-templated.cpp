#include <iostream>

template<typename T>
void apply(void (*operation)(T), T data) { // cdecl.org
    operation(data);
}

template<typename T>
void apply10(void (*operation)(T)) { // cdecl.org
    operation(10);
}

template<typename T>
void print(T x) {
    std::cout << x << "\n";
}

void print_twice(int x) {
    std::cout << x << ", " << x << "\n";
}

template<typename T>
void (*print_ptr)(T) = print;

int main() {
   apply<int>(print, 10);
   apply<int>(print_twice, 20);

   apply(print, 10);
   apply(print_twice, 20);

   // apply10(print);
   apply10(print_twice);

   [[maybe_unused]] void (*ptr1)(int) = print;
   [[maybe_unused]] void (*ptr2)(double) = print;
   ptr1 = print_twice;

   [[maybe_unused]] auto ptr3 = print_twice;
   //[[maybe_unused]] auto ptr4 = print;
   [[maybe_unused]] auto ptr5 = print<int>;

   // [[maybe_unused]] void (*ptr6)(int) = print_ptr;
   [[maybe_unused]] void (*ptr7)(int) = print_ptr<int>;
   [[maybe_unused]] auto ptr8 = print_ptr<int>;
}
