// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {  // abstract class
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived1 : Base {  // abstract class
    void foo() override {
    }
};

struct Derived2 : Base {  // abstract class
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
    void foo() override {  // Overrides foo() from all bases, no ambiguity.
    }
};

int main() {
    DerivedX *a = nullptr;
    a->foo();  // ambiguous: there are two foo()
    //a->Derived1::foo();  // no virtual
    //a->Derived1::bar();  // no virtual, undefined reference
}
