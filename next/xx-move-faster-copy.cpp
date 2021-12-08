#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

struct S {
    std::vector<int> vec;
};

int main() {
//    std::vector<int> v1(100000), v2;
    S v1, v2;
    v1.vec.resize(100000);
    for (int i = 0; i < 100000; i++) {
        using std::swap;
        swap(v1, v2);
    }
    std::cout << v1.vec.size() << "\n";
}
