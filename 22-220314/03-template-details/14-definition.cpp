template<typename T>
struct Foo {
    void foo(const Foo &other);

    Foo create_foo();

    static int static_field;
};

template<typename T>
void Foo<T>::foo(const Foo &) {
}

template<typename T>
Foo<T> Foo<T>::create_foo() {
}

template<typename T>
int Foo<T>::static_field = 10;

int main() {
    Foo<int> x;
    x.foo(x);

    Foo<char>::static_field = 10;
}
