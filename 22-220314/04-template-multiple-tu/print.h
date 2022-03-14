#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

template<typename T> void print(const T &value);  // Optional.

// Can be in a separate print_impl.h to decrease visual clutter.
//
// General implementation of print<> should always be in the header,
// so it can be implicitly instantiated on demand. Otherwise: undefined reference.
template<typename T> void print(const T &value) {
    std::cout << value << "\n";
}
// Out-of-scope: explicit instantiations for faster compilation: https://stackoverflow.com/a/59614755/767632
//               E.g. `std::string=std::basic_string<char>`

#endif  // PRINT_H_
