#ifndef A_H_
#define A_H_

#include <string>

// WARNING: still be careful with Static Initialization Order Fiasco!

// int var1;  // multiple definition
// std::string var2 = "hello";  // multiple definition
inline std::string var3 = "world";

// just declaration
extern int var1;
extern std::string var2;

// extern int var1 = 10;  // multiple definition (defined because of initialization)
// extern std::string var2 = "hello";  // multiple definition (defined because of initialization)

void foo();

#endif  // A_H_
