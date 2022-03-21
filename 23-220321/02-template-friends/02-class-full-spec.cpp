#include <vector>
#include <utility>

template<typename T>
struct Bar;

template<typename T>
struct Foo {
private:
    int x = 0;

    // One specific Bar<> is a friend. No way to partially specialize.
    friend struct Bar<std::vector<T>>;
};

template<typename T /* VecT may be a better name to avoid confusion */>
struct Bar {
    void bar() {
        // Foo<int>: friend struct Bar<vector<int>>.
        Foo<typename T::value_type> f;
        f.x = 10;

        [[maybe_unused]] Foo<void> g;
        // g.x = 10;

        [[maybe_unused]] Foo<T> h;
        // h.x = 10;
    }
};

int main() {
    Bar</*T=*/std::vector<int>>().bar();
}
