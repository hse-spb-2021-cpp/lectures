#ifndef A_H_
#define A_H_

#include <string>

// int var1 = 10;  // multiple definition
// std::string var2 = "hello";  // multiple definition

extern int var1;
extern std::string var2;

// extern int var1 = 10;  // multiple definition (defined because of initialization)
// extern std::string var2 = "hello";  // multiple definition (defined because of initialization)

void foo();

#endif  // A_H_
