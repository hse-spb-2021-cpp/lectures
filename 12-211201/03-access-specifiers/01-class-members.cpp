// https://en.cppreference.com/w/cpp/language/class

struct Base {
    Base() {}
    Base(int) {}
    void foo() {}
};

struct Foo : Base {
private:
    static int static_data_member;

    int non_static_data_member = 10;

    static void static_member_function() {  // definition, can be declaration
        static_data_member++;
        // non_static_data_member++;
        // this->non_static_data_member++;
    }

    void non_static_member_function() {  // definition, can be declaration
        static_data_member++;
        non_static_data_member++;
        this->non_static_data_member++;
    }

    typedef int MyInt1;
    using MyInt2 = int;

    enum MemberEnumeration { Foo1, Bar1 };
    enum class MemberEnumerationClass { Foo2, Bar2 };

    struct FooNestedClass {
        void foo(Foo *b) {
            b->non_static_data_member++;
        }
    };

    using Base::foo;
    void foo() {}

    // not affected by private/protected/public at all
    using Base::Base;  // constructors

    friend void do1(Foo);  // friend declarations
    friend void do2(Foo) {  // friend definitions
    }

    friend struct FriendOfFoo;  // friend declarations
};

int Foo::static_data_member = 100;

struct FriendOfFoo {
};

int main() {
}
