#include <vector>
#include <iostream>
#include <string>

int main() {
    std::vector<std::string> vec{
        "hello",
        "world"
    };
    std::cout << vec[0] << "\n";

    std::cout << std::vector{1, 2, 3}.size() << "\n";

    std::vector<int> vec2('a', 'b');  // vec2(97, 98);
    std::cout << vec2.size() << "\n";

    std::vector<int> vec3{'a', 'b'};
    std::cout << vec3.size() << "\n";  // 2 элемента: 97, 98.
}
