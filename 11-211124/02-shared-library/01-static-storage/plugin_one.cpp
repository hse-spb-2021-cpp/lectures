#include <boost/config.hpp>
#include <iostream>
#include "abstract_plugin.h"
#include "print_global_var.h"

class plugin_one : public abstract_plugin {
public:
    void foo() override {
        std::cout << "global_var is at " << &global_var() << "\n";
        global_var() += 20;
        std::cout << "global_var = " << global_var() << "\n";

        std::cout << "plugin: ";
        print_global_var();
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_one plugin;
plugin_one plugin;
