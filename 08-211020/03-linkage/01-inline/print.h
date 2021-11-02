#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>

inline void print(int value) {
    std::cout << "print(" << value << ")\n";
}

struct Printer {
    int value;

    static void newline();

    /*inline*/ void print() {
        std::cout << "Printer.print(), value=" << value;
        newline();
    }

    void foo();
};

inline void Printer::newline() {
    std::cout << "\n";
}

/*inline void Printer::print() {
    std::cout << "Printer.print(), value=" << value << "\n";
}*/

#endif  // PRINT_H_
