#include <memory>
// https://www.justsoftwaresolutions.co.uk/cplusplus/hidden-friends.html

namespace ns {
struct Foo {
private:
    int field = 10;

    // private/protected/public do not affect 'friend's
    friend void doit1(Foo *f);  // friend declaration

    friend void doit2a(Foo *f) {  // friend definition: hidden friend
        f->field++;
    }

    friend void doit2b(Foo *f) {  // friend definition: non-hidden friend
        f->field++;
    }

    friend void doit3() {  // Cannot be called, even from inside
        // doit3();
    }

    friend void consume(std::unique_ptr<Foo> &) {  // hidden friend
    }
};

void doit([[maybe_unused]] Foo *f) {
    // f->field++;
}

void doit1(Foo *f) {
    f->field++;
}

void doit2b(Foo *f);
}  // namespace ns

int main() {
    ns::Foo f;
    doit(&f);  // ADL: argument-dependent lookup
    doit1(&f);  // ADL
    doit2a(&f);  // ADL
    doit2b(&f);  // ADL
    ns::doit(&f);  // full qualification
    ns::doit1(&f);  // full qualification
    // ns::doit2a(&f);  // full qualification, but there is no 'ns::doit2a'
    ns::doit2b(&f);  // full qualification
}
