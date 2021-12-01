struct Base;
struct Derived;
struct SubDerived;

struct Base {
protected:
    void base_method(SubDerived &);
    static void base_static(SubDerived &);
};

struct Derived : Base {
protected:
    void derived_method(SubDerived &);
    static void derived_static(SubDerived &);

    friend struct FriendOfDerived;
};
struct OtherDerived : Base {};

struct SubDerived : Derived {
protected:
    void subderived_method(SubDerived &);
    static void subderived_static(SubDerived &);
};
struct OtherSubDerived : Derived {};

void Base::base_method(SubDerived &sd) {
    // Base is not a derived class of Derived or SubDerived
    sd.base_method(sd);
    // sd.derived_method(sd);
    // sd.subderived_method(sd);

    Base::base_static(sd);
    Derived::base_static(sd);
    SubDerived::base_static(sd);
    // Derived::derived_static(sd);
    // SubDerived::derived_static(sd);
    // SubDerived::subderived_static(sd);

    // Does not care about reference type.
    [[maybe_unused]] Base &b = sd;
    b.base_method(sd);
    [[maybe_unused]] Derived &d = sd;
    d.base_method(sd);
    // d.derived_method(sd);
}
void Base::base_static(SubDerived &) {
    // Same as base_method
}

void Derived::derived_method(SubDerived &sd) {
    sd.base_method(sd);
    sd.derived_method(sd);
    // sd.subderived_method(sd);

    Base::base_static(sd);
    Derived::base_static(sd);
    SubDerived::base_static(sd);
    Derived::derived_static(sd);
    SubDerived::derived_static(sd);
    // SubDerived::subderived_static(sd);

    // WARNING: can only see protected through 'Derived' or 'SubDerived', not 'Base'.
    [[maybe_unused]] Base &b = sd;
    // b.base_method(sd);

    // Reason:
    [[maybe_unused]] OtherDerived od;
    // od.base_method(sd);
    // static_cast<Base&>(od).base_method(sd);

    [[maybe_unused]] Derived &d = sd;
    d.base_method(sd);
    d.derived_method(sd);
}
void Derived::derived_static(SubDerived &) {
    // Same as derived_method
}

void SubDerived::subderived_method(SubDerived &sd) {
    sd.base_method(sd);
    sd.derived_method(sd);
    sd.subderived_method(sd);

    Base::base_static(sd);
    Derived::base_static(sd);
    SubDerived::base_static(sd);
    Derived::derived_static(sd);
    SubDerived::derived_static(sd);
    SubDerived::subderived_static(sd);

    // WARNING: can only see protected through 'SubDerived', not 'Base' or 'Derived'.
    [[maybe_unused]] Base &b = sd;
    // b.base_method(sd);
    [[maybe_unused]] Derived &d = sd;
    // d.base_method(sd);
    // d.derived_method(sd);
}
void SubDerived::subderived_static(SubDerived &) {}

int main() {
    [[maybe_unused]] SubDerived sd;
        // All members are protected here: not a friend of anyone.
}

struct BaseOfFriendOfDerived {
    void foo() {
        [[maybe_unused]] Derived d;
        [[maybe_unused]] SubDerived sd;
        // All members are protected here: not a friend of anyone.
    }
};

struct FriendOfDerived : BaseOfFriendOfDerived {
    void foo() {
        // WARNING: access to Base is unclear since C++17: https://stackoverflow.com/questions/60178872/why-can-t-protected-members-be-used-by-friends-of-derived-classes
        // Clang and GCC differ

        SubDerived sd;

        sd.base_method(sd);  // WARNING: unclear
        sd.derived_method(sd);
        // sd.subderived_method(sd);

        // Base::base_static(sd);  // WARNING: unclear
        Derived::base_static(sd);  // WARNING: unclear
        SubDerived::base_static(sd);  // WARNING: unclear
        Derived::derived_static(sd);
        SubDerived::derived_static(sd);
        // SubDerived::subderived_static(sd);

        // WARNING: can only see protected through 'SubDerived', not 'Base' or 'Derived'.
        [[maybe_unused]] Base &b = sd;
        // b.base_method(sd);  // WARNING: unclear
        [[maybe_unused]] Derived &d = sd;
        d.base_method(sd);  // WARNING: unclear
        d.derived_method(sd);
    }
};

struct DerivedFriendOfDerived : FriendOfDerived {
    void foo() {
        [[maybe_unused]] SubDerived sd;
        // All members are protected here: not a friend of anyone.
    }
};
