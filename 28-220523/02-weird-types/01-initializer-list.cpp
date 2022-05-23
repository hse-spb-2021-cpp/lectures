#include <cassert>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <vector>

struct Foo {
    int val;
    Foo(int x, int y) : val(10 * x + y) {
    }
};

struct Bar {
    Bar(std::initializer_list<int> x) {
        std::cout << x.size() << " " << *x.begin() << "\n";
    }
    Bar(std::initializer_list<Foo> x) {
        std::cout << x.size() << " " << x.begin()->val << "\n";
    }
    Bar([[maybe_unused]] std::initializer_list<std::unique_ptr<int>> x) {
        // std::unique_ptr<int> y = std::move(*x.begin());  // Oops :(
    }
};

struct Baz {
    int val;
    std::vector<Baz> children;

    Baz(int val_) : val(val_) {
    }
    Baz(std::initializer_list<Baz> children_)
        : val(-1), children(children_.begin(), children_.end()) {
    }

    void print() const {
        if (val >= 0) {
            assert(children.empty());
            std::cout << val;
        } else {
            std::cout << "{";
            for (const auto &c : children)
                c.print();
            std::cout << "}";
        }
    }
};

int main() {
    Bar{1, 2, 3, 4};
    Bar{{1, 2}, {3, 4}, {5, 6}};
    Baz{
        1,             //
        2,             //
        {3, 4},        //
        {{5}},         //
        {{6}, 7, {}},  //
        8              //
    }
        .print();
    std::cout << "\n";
}
