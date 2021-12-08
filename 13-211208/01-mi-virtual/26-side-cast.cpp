#include <iostream>
#include <cstddef>

struct Base1 { virtual ~Base1() {} };
struct Base2 { virtual ~Base2() {} };
struct Base3 { virtual ~Base3() {} };

/*
  B1  B2  B3
  /\  /\  /\
 /  \/  \/  \
D1  12  23  D3
  \  \  /   /
   --\\//---
      DX
*/
struct Derived1 : virtual Base1 {};
struct Derived12 : virtual Base1, virtual Base2 {};
struct Derived23 : virtual Base2, virtual Base3 {};
struct Derived3 : virtual Base3 {};

struct DerivedX : Derived1, Derived12, Derived23, Derived3 {};

struct CompletelyUnrelated {};
struct DerivedXXX : Derived1, CompletelyUnrelated {};

void foo(Derived1 &d1) {
    std::cout << dynamic_cast<Derived3*>(&d1) << "\n";
    std::cout << dynamic_cast<CompletelyUnrelated*>(&d1) << "\n";
}

int main() {
    DerivedX a;
    foo(a);

    DerivedXXX b;
    foo(b);
}
