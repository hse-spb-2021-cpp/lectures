#ifndef PLUGIN_API_H_
#define PLUGIN_API_H_

#include <boost/config.hpp>
#include <memory>

class BOOST_SYMBOL_VISIBLE base {
public:
    int some_value = 123;

    void say_non_virtual_hi() {
        std::cout << "non_virtual_hi\n";
        std::cout << "some_value = " << some_value << "\n";
    }
    virtual void say_hi() = 0;
    virtual ~base() = default;
};

class BOOST_SYMBOL_VISIBLE derived1 : public base {
public:
    void say_hi() override {
        std::cout << "hi from derived1\n";
    }
};

class BOOST_SYMBOL_VISIBLE abstract_plugin {
public:
    virtual std::unique_ptr<base> create_base() = 0;
    virtual ~abstract_plugin() = default;
};

#endif  // PLUGIN_API_H_
