#include <string>

struct Foo {
    Foo(const std::string&) {}
};

void call_with_foo(const Foo&) {
}

int main() {
    call_with_foo(Foo(std::string("hello")));
    call_with_foo(Foo("hello"));
    call_with_foo(std::string("hello"));
//    call_with_foo("hello");

    {
        using namespace std::literals;
        call_with_foo("hello"s);  // user-defined literal
    }
}
