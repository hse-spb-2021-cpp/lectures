#include <cstddef>

template<int ...Ns>  // Template parameter pack, but of values instead of types.
struct Foo {
    static constexpr inline std::size_t M = sizeof...(Ns);
};
Foo<> b1;            // M = 0
Foo<10, 20, 30> b2;  // M = 3

int func() { return 0; }
void foo(int a, int (*b)()) {}

template<typename ...Ts>
struct Combo {
    // Pack expansion to provide exact types of values.
    template<Ts ...Values> struct Inside {
        void doit() {
            // Just like a function parameter pack.
            // As foo is not templated, it requires specific `Ts...`.
            foo(Values...);
        }
    };
};
Combo<int, int(*)()>::Inside<10, func> x;
// Combo<int, int(*)()>::Inside<func, func> y;  // type mismatch

// Since C++17: each value can have an independent type.
template<auto Value> struct WithValue {};
WithValue<10> y;
template<auto ...Values> struct WithValues {};
WithValues<10, func, func> z;
