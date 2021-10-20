// https://en.cppreference.com/w/cpp/language/implicit_conversion

struct Foo {
    Foo(int) {}
};

struct Bar {
    Bar(const Foo&) {}
};

void call_with_bar(const Bar&) {
}

int main() {
    // Standard conversions like 'Bar -> const Bar' are boring and ommitted.
    call_with_bar(Bar(Foo(10)));  // no implicit conversions
    call_with_bar(Bar(Foo(10LL)));  // standard implicit conversion long long -> int
    call_with_bar(Foo(10));  // user-defined implicit conversion Foo -> Bar
    call_with_bar(Bar(10));  // user-defined implicit conversion int -> Foo
    call_with_bar(Bar(10LL));  // standard implicit conversion long long -> int + user-defined implicit conversion int -> Bar
    // call_with_bar(10);  // needs two user-defined implicit conversions: int -> Foo -> Bar
}
