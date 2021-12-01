struct Foo {
private:
    int field = 10;

    struct NestedClass {  // E.g.: hash_table::iterator
        void foo(Foo *b) {
            b->field++;
        }
    };

public:
    using get_result = NestedClass;

    NestedClass get_nc() {
        NestedClass obj;
        return obj;
    }
};

int main() {
    Foo f;
    // Foo::NestedClass nc1 = f.get();

    auto nc2 = f.get_nc();
    nc2.foo(&f);

    Foo::get_result nc3 = f.get_nc();
    nc3.foo(&f);

    [[maybe_unused]] Foo::get_result nc4;
    [[maybe_unused]] decltype(f.get_nc()) nc5;
}
