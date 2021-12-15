#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

struct Greater {
    bool operator()(int a, int b) const {  // Functor.
        return a > b;
    }
};

int main() {
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    Greater g;
    assert(g(5, 4));
    assert(!g(4, 5));
    sort(v.begin(), v.end(), g /* Greater() */);
    for (int x : v) {
        std::cout << x << "\n";
    }
}
