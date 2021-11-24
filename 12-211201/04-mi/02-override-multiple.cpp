// https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister

struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived1 : Base {
    void foo() override {
    }
};

struct Derived2 : Base {
    void bar() override {
    }
};

struct DerivedX : Derived1, Derived2 {
    // void foo() override {  // Перезапишет foo() сразу изо всех базовых классов, даже без виртуального наследования.
                              // Исчезнет неоднозначность.
                              // См. 19-210302/01-old/02-mi-override.cpp
    // }
};

int main() {
    DerivedX *a = nullptr;
    a->foo();  // ambiguous: foo() существует в двух экземплярах
    //a->Derived1::foo();  // без виртуальности
    //a->Derived1::bar();  // без виртуальности, undefined reference.
}
