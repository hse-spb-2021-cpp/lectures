// Order:
// 1. Name resolution. Output: "overload set".
// 2. Overload resolution. Output: a single overload.
// 3. Access check.
// 4. Call, can be virtual or non-virtual.

struct Foo {
private:
    void foo(int) {}

public:
    void foo(double) {}
    // void foo(int, int = 10) {}  // ambiguous
};

int main() {
    Foo f;
    f.foo(10);  // chooses foo(int), it is private, compilation error
    // Reason: we would like that changing 'private' to 'public' never alters the behavior.
}
