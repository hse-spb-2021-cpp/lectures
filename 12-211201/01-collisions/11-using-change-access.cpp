struct Base {
protected:
    void magic() {
    }  // Similarly for fields.
};

struct Derived : Base {
    using Base::magic;
};

struct SubDerived : Derived {
    void magic2() {
        magic();
        Base::magic();
        Derived::magic();
    }

private:
    using Derived::magic;
};

int main() {
    [[maybe_unused]] Base b;
    // b.magic();

    Derived d;
    d.magic();
    // d.Base::magic();

    SubDerived sd;
    // sd.magic();
    // sd.Base::magic();
    sd.Derived::magic();
    sd.magic2();
}

struct SubSubDerived : SubDerived {
    // using Base::magic;
    // using Derived::magic;
    // using SubDerived::magic;
    void magic3() {
        Base::magic();
        Derived::magic();
        // SubDerived::magic();
        // magic();  // SubDerived::magic()
    }
};
