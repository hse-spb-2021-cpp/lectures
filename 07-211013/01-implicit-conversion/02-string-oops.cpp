#include <string>

struct Foo {
    Foo(const std::string&) {}
};

void call_with_foo(const Foo&) {
}

int main() {
    call_with_foo(Foo(std::string("hello")));
    call_with_foo(Foo("hello"));  // const char[6] -> std::string is a 'user-defined' conversion
    call_with_foo(std::string("hello"));
    // call_with_foo("hello");  // needs two user-defined conversions

    {
        using namespace std::literals;
        call_with_foo("hello"s);  // user-defined literal: "hello"s is std::string
        // [[maybe_unused]] int s;  // 's' is not a reserved name.
    }
}
