#include <stddef.h>
#include <iostream>

// C library
void foreach(
    void *begin,
    size_t element_size,
    size_t n,
    void (*f)(void *user_data, void *element),
    void *user_data
) {
    for (size_t i = 0; i < n; i++, begin = (char*)begin + element_size) {
        f(user_data, begin);
        // f(begin, user_data);  // compiles as well
    }
}

// C++ code
int main() {
    int arr[] = {1, 2, 3};
    int x = 123;
    foreach(
        arr,
        sizeof(int),
        3,
        [](void *user_data, void *element) {
            std::cout << *static_cast<int*>(user_data) << " " << *static_cast<int*>(element) << "\n";
        },
        &x
   );
}
