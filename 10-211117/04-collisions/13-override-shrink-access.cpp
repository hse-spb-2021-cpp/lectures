struct Base {
private:
    virtual void foo() {
    }
    virtual void foo2() {
    }

protected:
    virtual void bar() {
    }
    virtual void bar2() {
    }

public:
    virtual void baz() {
    }
    virtual void baz2() {
    }
};

struct Derived : Base {
private:
    void foo() override {
    }
    void bar() override {
    }
    void baz() override {
    }

    void qwe() {
        foo();
        // foo2();

        bar();
        bar2();

        baz();
        baz2();
    }
};

int main() {
    Derived d;
    // d.foo();
    // d.foo2();
    // d.bar();
    // d.bar2();
    // d.baz();
    d.baz2();

    Base &b = d;
    // b.foo();
    // b.foo2();
    // b.bar();
    // b.bar2();
    b.baz();
    b.baz2();
}
