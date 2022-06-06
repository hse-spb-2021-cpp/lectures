#ifndef A_H_
#define A_H_

#include <string>

inline constexpr char str1[] = "Hello";  // The best.
inline const std::string str2 = "World";  // Does not work in Visual Studio: https://abseil.io/tips/140#non-portable-mistake
constexpr char str3[] = "My";  // Implies inline since C++17
const std::string str4 = "Dear";

struct Foo {
    static inline constexpr char str1[] = "1";
    static inline const std::string str2 = "2";
    static constexpr char str3[] = "3";  // Implies inline since C++17
    // static const std::string str4 = "4";
    static const std::string str4;
};

void foo();

#endif  // A_H_
