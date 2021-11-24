#ifndef PLUGIN_API_H_
#define PLUGIN_API_H_

#include <boost/config.hpp>
#include <memory>

BOOST_SYMBOL_VISIBLE inline int &global_var() {
    static int global_var = 1000;
    return global_var;
}

class BOOST_SYMBOL_VISIBLE abstract_plugin {
public:
    virtual void foo() = 0;
    virtual ~abstract_plugin() = default;
};

#endif  // PLUGIN_API_H_
