#include "print_global_var.h"
#include "abstract_plugin.h"
#include <iostream>

void print_global_var() {
    std::cout << "global_var() = " << global_var() << "\n";
}
