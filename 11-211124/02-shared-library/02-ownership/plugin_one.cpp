#include <boost/config.hpp>
#include <iostream>
#include <string>
#include "abstract_plugin.h"

class plugin_one : public abstract_plugin {
public:
    plugin_one() {
        std::cout << "Constructing plugin_one\n";
    }

    std::unique_ptr<base> create_base() override {
        auto result = std::make_unique<derived1>();
        result->some_value = 456;
        return result;
    }

    ~plugin_one() {
        std::cout << "Destructing plugin_one\n";
    }
};

extern "C" BOOST_SYMBOL_EXPORT plugin_one plugin;
plugin_one plugin;
