#include <string>

struct Foo {
    explicit Foo() {}
    explicit Foo(int, std::string) {}
};

void call(const Foo &) {
}

Foo ret() {
    return {};
    // return Foo{};

    // return {10, "hello"};
    // return Foo{10, "hello"};
}

int main() {
    [[maybe_unused]] Foo f1{10, "hello"};

    [[maybe_unused]] Foo f2 = {10, "hello"};
    // [[maybe_unused]] Foo f2 = Foo{10, "hello"};

    [[maybe_unused]] Foo f3{};

    [[maybe_unused]] Foo f4 = {};
    // [[maybe_unused]] Foo f4 = Foo{};

    call({10, "hello"});
    // call(Foo{10, "hello"});

    call({});
    // call(Foo{});

    ret();
}
