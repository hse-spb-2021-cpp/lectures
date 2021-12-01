struct Base {
private:
    static void base() {}
};

struct Derived : Base {
private:
    static void derived() {}

    void foo();
};

struct SubDerived : Derived {
private:
    static void subderived() {} 
};

void Derived::foo() {
    derived();
    // SubDerived::base();
    SubDerived::derived();  // Actually a name for Derived::derived(), there is no 'using'
    // SubDerived::subderived();

    SubDerived sd;
    sd.derived();
    sd.SubDerived::derived();
}

int main() {
}
