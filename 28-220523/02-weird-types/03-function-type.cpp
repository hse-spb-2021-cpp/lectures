#include <functional>

void func1();
void func2(int x);
void func3(int y);
int func4(int x, char y);

template<typename> struct TD;
TD<decltype(func1)> a; // TD<void()>
TD<decltype(func2)> b; // TD<void(int)>
TD<decltype(func3)> c; // TD<void(int)>
TD<decltype(func4)> d; // TD<int(int, char)>

// decltype(func1) x;  // Cannot create a variable of this type.
std::function<void(int)> y;  // frequently used as a template parameter

using func1_ptr = void(*)();
func1_ptr z = func1;  // implicitly convertible to a pointer
