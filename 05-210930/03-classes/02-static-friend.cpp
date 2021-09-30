// friend: defined inside or outside; hidden friends
// static: defined inside or outside
struct Foo {
private:
    int x;

public:
    friend void foo(Foo &f) {
        f.x = 10;
    }

    static void bar(Foo &f) {  // Also a friend.
        f.x = 10;
    }
};

// Can also define outside:
// void foo(Foo &)
// void Foo::bar(Foo &)

int main() {
    Foo f;
    foo(f);

    Foo::bar(f);
}
