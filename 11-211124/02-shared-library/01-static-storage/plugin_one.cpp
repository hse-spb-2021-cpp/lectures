#include <boost/config.hpp>
#include <iostream>
#include <string>
#include "abstract_plugin.h"

class plugin_one : public abstract_plugin {
public:
    void foo() override {
        std::cout << "global_var is at " << &global_var() << "\n";
        global_var() += 20;
        std::cout << "global_var = " << global_var() << "\n";
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_one plugin;
plugin_one plugin;
