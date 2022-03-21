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

template<typename T>
struct Bar {
    void bar() {
        Foo<typename T::value_type> f;
        f.x = 10;

        [[maybe_unused]] Foo<void> g;
        // g.x = 10;
    }
};

int main() {
    Bar<std::vector<int>>().bar();
}
