#include <string>
#include <iostream>

int main() {
    std::string s = "123";
    s += "456";
    // s == 123456
    std::cout << s + s << "\n";
    std::cout << s.size() << "\n";
    std::cout << s[2] << "\n";
    s[2] = 'x';
    std::cout << s << "\n";
    std::cout << s + "MEOW" << "\n";

    // std::cout << s * 2 << "\n";

    std::string s2;
    s2.push_back('x');
    // std::cout << "MEOW" + "MEOW" << "\n";
    std::cout << static_cast<std::string>("MEOW") + "MEOW" << "\n";
    std::cout << std::string("MEOW") + "MEOW" << "\n";

    std::cout << std::to_string(123) << "\n";  // C++11
    std::string s3 = "123";
    std::cout << std::stoi(s3) << "\n";  // C++11
}
