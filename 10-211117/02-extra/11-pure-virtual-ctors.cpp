#include <iostream>

struct Base {
    int value = 123;

    virtual void printTo() = 0;

    Base() {
        printTo();
    }
};

struct Derived : Base {
    void printTo() override {
    }
};

int main() {
    Derived d;
}
