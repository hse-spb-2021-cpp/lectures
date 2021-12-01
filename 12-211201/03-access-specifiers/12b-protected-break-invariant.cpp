#include <cassert>

struct Base {
protected:
    int field = 10;
    void inc_field() {
        field++;
    }
};

struct Derived1 : Base {
private:
    int field_dup = field;

public:
    void inc_field() {
        Base::inc_field();
        field_dup++;
    }
    void check_invariant() {
        assert(field == field_dup);
    }
};

struct Derived2 : Base {
    void foo(Base *b) {
        // b->inc_field();
    }
};

int main() {
    Derived1 d1;
    d1.inc_field();
    // d1.Base::inc_field();  // Break invariant!

    Derived2{}.foo(&d1);  // Break invariant?
}
