#include <iostream>

int main() {
    const char *s_ptr;
    {
        // Small string optimization
        std::string s = "hello";
//        std::string s = "hello 1234567890654345678986434567898643456789097654";
        s_ptr = s.c_str();
        std::cout << s_ptr << " (1)\n";
    }
    std::cout << s_ptr << " (2)\n";
}
