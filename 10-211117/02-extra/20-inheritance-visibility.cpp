struct Base {
    void foo() {
    }
};

struct Derived1 : public Base {};  // Default for 'struct', the most popular.
struct Derived2 : protected Base {};
struct Derived3 : private Base {};  // Default for 'class'.

struct Derived22 : Derived2 {
    void bar() {
        foo();
        Derived2 d2;
        const Base &b2 = d2;
    }
};

struct Derived33 : Derived3 {
    void bar() {
        // foo();
        // const Base &b2 = *this;
    }
};

int main() {
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    d1.foo();
    // d2.foo();

    const Base &b1 = d1;
    // const Base &b2 = d2;
}
