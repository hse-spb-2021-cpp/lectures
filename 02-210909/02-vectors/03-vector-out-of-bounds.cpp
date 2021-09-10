// #define _GLIBCXX_DEBUG
// #define _LIBCPP_DEBUG
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(5);
    vec[10] = 5;  // Undefined Behavior!
/*    int vec[5];
    int *vec2 = vec;
    vec2[1000] = 5;*/
    std::cout << vec[10] << "\n";
}
