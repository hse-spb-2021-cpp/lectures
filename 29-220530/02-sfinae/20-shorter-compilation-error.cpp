#include <algorithm>
#include <vector>

struct Foo {
};

template<typename It>
auto my_sort(It begin, It end) -> decltype(*begin < *end, void()) {
    std::sort(begin, end);
}

int main() {
    std::vector<Foo> v;
    std::sort(v.begin(), v.end());  // long compilation error
    my_sort(v.begin(), v.end());  // short compilation error
}
