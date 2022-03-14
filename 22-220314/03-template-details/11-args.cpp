#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

// For both class and function templates:

// 'class' == 'typename' in the line below. 'struct' is not allowed.
template<typename C = int, typename = char, typename = double, int = 10>
struct templ_foo {
};
templ_foo<std::vector<int>, char, bool> x;
templ_foo<std::vector<int>> y;
templ_foo<> z;

// Types/default values of following parameters may depend on prior.
template<typename C, C value, typename D = std::pair<C, C>>
struct templ_bar {
};
templ_bar<int, 10> xx;
templ_bar<unsigned, 4'000'000'000> yy;

// You may want a template of a specific 'kind' as a paremeter. Works with argument deduction as well.
template<typename T, template<typename> typename Container = std::vector>  // Even though std::vector<T, Alloc>!
struct heap {
    Container<std::pair<T, int>> data;  // (value, id)
};

int main() {
    heap<std::string> h1;
    h1.data.emplace_back("hello", 20);

    heap<std::string, std::set> h2;  // Does not make much sense, but compiles.
    h2.data.emplace("hello", 20);

    // heap<int, std::map> h3;
}