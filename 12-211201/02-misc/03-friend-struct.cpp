struct Foo {
private:
    int x = 0;

    friend struct Bar;  // Assumes in the current namespace
};

struct Bar {
    void foo(Foo &f) {
        f.x++;
    }
    static void sfoo(Foo &f) {
        f.x++;
    }
};

int main() {
    Foo f;
    // f.x++;

    Bar b;
    b.foo(f);
    b.sfoo(f);
    Bar::sfoo(f);
}
