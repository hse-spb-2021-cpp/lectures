#include <boost/config.hpp>
#include <iostream>
#include <string>
#include "abstract_plugin.h"

class plugin_one : public abstract_plugin {
public:
    plugin_one() {
        std::cout << "plugin_one: sizeof(std::string) = " << sizeof(std::string)
                  << "\n";
    }

    const std::string &get_string() override {
        static std::string s = "hello from plugin";
        return s;
    }

    void print_string(const std::string &s) override {
        std::cout << "print_string(" << s << ")\n";
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_one plugin;
plugin_one plugin;
