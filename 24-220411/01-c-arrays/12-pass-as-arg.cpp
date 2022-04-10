#include <iostream>
#include <iterator>
#include <cstddef>

// void foo(int arr[]) {  // Actually void foo(int *arr)
// void foo(int arr[5]) {  // Actually void foo(int *arr)
void foo(int arr[15]) {  // Actually void foo(int *arr)
    // Careful: sizeof pointer
    std::cout << "arr[0] = " << arr[0] << ", sizeof = " << sizeof(arr) << "\n";
}

void foo_good(int arr[], int arr_len) {
    std::cout << "arr[0] = " << arr[0] << ", len = " << arr_len << "\n";
}

void foo_cpp_wtf(int (&arr)[10]) {  // C++-only, ok
// void foo_cpp_wtf(int (&arr)[5]) {  // C++-only, compilation error if size mismatched
// void foo_cpp_wtf(int (&arr)[15]) {  // C++-only, compilation error if size mismatched
    std::cout << "arr[0/10] = " << arr[0] << "\n";
}

template<std::size_t N>
void foo_cpp_templ(int (&arr)[N]) {  // Just like std::size
    std::cout << "N = " << N << ", last = " << arr[N - 1] << "\n";
}

int main() {
    int arr[10]{1, 2, 3};
    foo(arr);
    foo_good(arr, sizeof arr / sizeof arr[0]);  // C style.
    foo_cpp_wtf(arr);
    foo_cpp_templ(arr);
}
