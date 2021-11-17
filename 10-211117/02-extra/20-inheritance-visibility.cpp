struct Base {
    void foo() {
    }
};

struct Derived1 : public Base {};  // Default for 'struct', the most popular.
struct Derived2 : protected Base {};
struct Derived3 : private Base {  // Default for 'class'.
    void baz() {
        foo();
        Derived3 d3;
        const Base &b = d3;
    }
};

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
        [[maybe_unused]] ::Base b;  // :: is important
        // const ::Base &b2 = *this;
        // const ::Base &b3 = static_cast<const ::Base &>(*this);
        const ::Base &b4 = (const ::Base &)*this;  // meh, C-style cast ignores access modifiers
    }
};

int main() {
    Base b;
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    b.foo();
    d1.foo();
    // d2.foo();
    // d3.foo();

    const Base &b1 = d1;
    // const Base &b2 = d2;
    const ::Base &b2 = (const Base &)d2;  // meh, C-style cast ignores access modifiers
    // const Base &b3 = d3;
    const ::Base &b3 = (const Base &)d3;  // meh, C-style cast ignores access modifiers
}
