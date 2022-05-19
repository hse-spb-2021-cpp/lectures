#include <stddef.h>
#include <iostream>

// C library
typedef struct array_data_ *ArrayData;
typedef struct user_data_ *UserData;

void foreach(
    ArrayData begin,
    size_t element_size,
    size_t n,
    void (*f)(UserData user_data, ArrayData element),
    UserData user_data
) {
    for (size_t i = 0; i < n; i++, begin = (ArrayData)((char*)begin + element_size)) {
        f(user_data, begin);
        // f(begin, user_data);  // compilation error now
    }
}

// C++ code
int main() {
    int arr[] = {1, 2, 3};
    int x = 123;
    foreach(
        reinterpret_cast<ArrayData>(arr),
        sizeof(int),
        3,
        [](UserData user_data, ArrayData element) {
            std::cout << *reinterpret_cast<int*>(user_data) << " " << *reinterpret_cast<int*>(element) << "\n";
        },
        reinterpret_cast<UserData>(&x)
   );
}
