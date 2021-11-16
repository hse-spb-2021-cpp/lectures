class Base {
public:
    void foo() {
    }
};

class Derived : /* private */ Base {};

int main() {
    Derived d;
    d.foo();
}
