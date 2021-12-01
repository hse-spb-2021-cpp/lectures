struct Base;
struct Derived;
struct SubDerived;

struct Base {
private:
    void base_method(SubDerived &);
    static void base_static(SubDerived &);
};

struct Derived : Base {
private:
    void derived_method(SubDerived &);
    static void derived_static(SubDerived &);

    friend struct FriendOfDerived;
};

struct SubDerived : Derived {
private:
    void subderived_method(SubDerived &);
    static void subderived_static(SubDerived &);
};

void Base::base_method(SubDerived &sd) {
    sd.base_method(sd);
    // sd.derived_method(sd);
    // sd.subderived_method(sd);

    Base::base_static(sd);
    Derived::base_static(sd);
    SubDerived::base_static(sd);
    // Derived::derived_static(sd);
    // SubDerived::derived_static(sd);
    // SubDerived::subderived_static(sd);
}
void Base::base_static(SubDerived &) {
    // Same as base_method
}

void Derived::derived_method(SubDerived &sd) {
    // sd.base_method(sd);
    sd.derived_method(sd);
    // sd.subderived_method(sd);

    // Base::base_static(sd);
    // Derived::base_static(sd);
    // SubDerived::base_static(sd);
    Derived::derived_static(sd);
    SubDerived::derived_static(sd);
    // SubDerived::subderived_static(sd);
}
void Derived::derived_static(SubDerived &) {
    // Same as derived_method
}

void SubDerived::subderived_method(SubDerived &sd) {
    // sd.base_method(sd);
    // sd.derived_method(sd);
    sd.subderived_method(sd);

    // Base::base_static(sd);
    // Derived::base_static(sd);
    // SubDerived::base_static(sd);
    // Derived::derived_static(sd);
    // SubDerived::derived_static(sd);
    SubDerived::subderived_static(sd);
}
void SubDerived::subderived_static(SubDerived &) {}

int main() {
    [[maybe_unused]] SubDerived sd;
    // All members are private here: not a friend of anyone.
}

struct BaseOfFriendOfDerived {
    void foo() {
        [[maybe_unused]] Derived d;
        [[maybe_unused]] SubDerived sd;
        // All members are private here: not a friend of anyone.
    }
};

struct FriendOfDerived : BaseOfFriendOfDerived {
    void foo() {
        SubDerived sd;

        // sd.base_method(sd);
        sd.derived_method(sd);
        // sd.subderived_method(sd);

        // Base::base_static(sd);
        // Derived::base_static(sd);
        // SubDerived::base_static(sd);
        Derived::derived_static(sd);
        SubDerived::derived_static(sd);
        // SubDerived::subderived_static(sd);
    }
};

struct DerivedFriendOfDerived : FriendOfDerived {
    void foo() {
        [[maybe_unused]] SubDerived sd;
        // All members are private here: not a friend of anyone.
    }
};
