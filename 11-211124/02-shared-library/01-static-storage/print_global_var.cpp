#include "print_global_var.h"
#include <iostream>
#include "abstract_plugin.h"

void print_global_var() {
    std::cout << "global_var() = " << global_var() << "\n";
}
