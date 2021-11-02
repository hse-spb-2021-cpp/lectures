#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <iterator>

void print_all(int *beg, int *en) {
    // Just like iterators
    for (int *it = beg; it != en; it++) {
        std::cout << *it << "\n";
    }
}

int main() {
    int data[]{40, 20, 10, 30};

    int *one_past_end = data + 4;
    assert(one_past_end - data == 4);
    // int x = *one_past_end;  // dereference is UB.

    std::sort(data, data + 4);
    std::sort(std::begin(data), std::end(data));  // better
    print_all(data, data + 4);

    // int *ub1 = data - 1;
    // int *ub2 = data - 1 + 1;
    // int *ub3 = data + 5;
}
