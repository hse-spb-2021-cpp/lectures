struct Foo;
struct Bar;

Bar &create_b1();
Bar &create_b2();
Foo &create_f();

int main() {
    create_b1();
    create_f();
    create_f();
    create_b2();
    create_f();
}
