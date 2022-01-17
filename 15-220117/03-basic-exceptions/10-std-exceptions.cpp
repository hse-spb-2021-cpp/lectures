#include <exception>
#include <iostream>
#include <vector>
#include <string>

int main() {
    try {
        // std::vector<int> vec(-1);  // std::bad_alloc
        // std::cout << std::stoi("123") << "\n";
        // std::cout << std::stoi("foo") << "\n";  // std::invalid_argument
        // std::cout << std::vector<int>(10).at(15) << "\n";  // std::out_of_bounds
        // See Boost::Dll example
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}
