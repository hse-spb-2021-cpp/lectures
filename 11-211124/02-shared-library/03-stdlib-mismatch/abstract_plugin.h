#ifndef PLUGIN_API_H_
#define PLUGIN_API_H_

#include <boost/config.hpp>
#include <string>

class BOOST_SYMBOL_VISIBLE abstract_plugin {
public:
    virtual const std::string &get_string() = 0;
    virtual void print_string(const std::string &) = 0;
    virtual std::string create_string() = 0;
    virtual void consume_string(std::string s) = 0;
    virtual ~abstract_plugin() = default;
};

#endif  // PLUGIN_API_H_
