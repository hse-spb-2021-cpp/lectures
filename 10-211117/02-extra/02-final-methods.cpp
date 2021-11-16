struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived : Base {
    void foo() final {
    }

    // 'override' is redundant:
    // void fooo() final {}  // CE, which is fine.
    // virtual void fooo() final {}  // Not CE, which is not fine.

    void bar() override {
    }
};

struct SubDerived : Derived {
    // void foo() override {}

    void bar() override {
    }
};

int main() {
}
