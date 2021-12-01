struct Base;
struct Derived;
struct SubDerived;

struct Base {
    void base_method(SubDerived &);
    static void base_static(SubDerived &);
};

struct Derived : Base {
    void derived_method(SubDerived &);
    static void derived_static(SubDerived &);

    friend struct FriendOfDerived;
};

struct SubDerived : Derived {
    void subderived_method(SubDerived &);
    static void subderived_static(SubDerived &);
};

void Base::base_method(SubDerived &) {}
void Base::base_static(SubDerived &) {}

void Derived::derived_method(SubDerived &) {}
void Derived::derived_static(SubDerived &) {}

void SubDerived::subderived_method(SubDerived &) {}
void SubDerived::subderived_static(SubDerived &) {}

int main() {
    SubDerived sd;
    sd.base_method(sd);
    sd.derived_method(sd);
    sd.subderived_method(sd);
    Base::base_static(sd);
    Derived::derived_static(sd);
    SubDerived::subderived_static(sd);
}

struct BaseOfFriendOfDerived {
    void foo() {
        SubDerived sd;
        sd.base_method(sd);
        sd.derived_method(sd);
        sd.subderived_method(sd);
        Base::base_static(sd);
        Derived::derived_static(sd);
        SubDerived::subderived_static(sd);
    }
};

struct FriendOfDerived : BaseOfFriendOfDerived {
    void foo() {
        SubDerived sd;
        sd.base_method(sd);
        sd.derived_method(sd);
        sd.subderived_method(sd);
        Base::base_static(sd);
        Derived::derived_static(sd);
        SubDerived::subderived_static(sd);
    }
};

struct DerivedFriendOfDerived : FriendOfDerived {
    void foo() {
        SubDerived sd;
        sd.base_method(sd);
        sd.derived_method(sd);
        sd.subderived_method(sd);
        Base::base_static(sd);
        Derived::derived_static(sd);
        SubDerived::subderived_static(sd);
    }
};
