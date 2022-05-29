#include <type_traits>

// How about we use functions instead of specializations?
// Let's make a tag value for each type
// See https://stackoverflow.com/a/38009838/767632 and https://www.boost.org/doc/libs/1_79_0/libs/hana/doc/html/index.html
template<typename T> struct type_ { using type = T; };
template<typename T> constexpr type_<T> type_c;

template<typename...> struct types_ {};
template<typename ...Ts> constexpr types_<Ts...> types_c;

template<typename T, typename ...Ts>
auto head(types_<T, Ts...>) { return type_c<T>; }

template<typename T, typename ...Ts>
auto tail(types_<T, Ts...>) { return types_c<Ts...>; }

// Nice syntax!
template<typename T>
auto second(T t) { return head(tail(t)); }

// Not so nice syntax, but helpers help.
static_assert(std::is_same_v<
    decltype(second(types_c<int, short, double>))::type,
    short
>);

int main() {}
