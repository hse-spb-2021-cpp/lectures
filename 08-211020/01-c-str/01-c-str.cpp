#include <iterator>
#include <iostream>

// C-style string / строки в стиле си / сишные строки
// null-terminated string
// ASCIIZ string

int main() {
    const char str[] = "hello";
    std::cout << std::size(str) << "\n";
    std::cout << str << "\n";

    const char *str_ptr = str;  // array-to-pointer decay
    std::cout << str_ptr << "\n";

    const char *str_ptr2 = &str[2];
    std::cout << str_ptr2 << "\n";

    const char strs[] = "hello\0world\0botva";
    std::cout << &strs[1] << "\n";
    std::cout << &strs[6] << "\n";
    std::cout << &strs[12] << "\n";
}
