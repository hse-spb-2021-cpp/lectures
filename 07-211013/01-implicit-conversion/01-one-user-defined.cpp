// https://en.cppreference.com/w/cpp/language/implicit_conversion

struct Foo {
    Foo(long long) {}
};

struct Bar {
    Bar(const Foo&) {}
};

void call_with_bar(const Bar&) {
}

int main() {
    call_with_bar(Bar(Foo(10LL)));
    call_with_bar(Bar(Foo(10)));
    call_with_bar(Foo(10));
    // call_with_bar(10);
}
