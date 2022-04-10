#include <cassert>
#include <iterator>
#include <iostream>

const int N = 5;

int main() {
    // "C-arrays", "plain arrays"
    int arr[2 * N];  // 10 uninitialized ints one after another
                     // Automatic storage duration
                     // Size should be a compile-time expression
    assert(std::size(arr) == 10);  // C++-style
    assert(sizeof(arr) == 10 * sizeof(int));  // C style
    assert(sizeof(arr) / sizeof(arr[0]) == 10);  // C style
    arr[2] = 123;
    assert(arr[2] == 123);
    // std::cout << arr[10];  // UB
    
    // No push_back/pop_back/insert/operator=/copying/...
    // int arr2[2 * N] = arr;  // Just does not compile

    // range-based-for is ok, though
    for (int &x : arr) {
        x = 10;
    }
}
