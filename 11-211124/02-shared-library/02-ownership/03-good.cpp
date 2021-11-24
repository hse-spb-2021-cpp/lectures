#include <boost/dll/import.hpp>
#include <boost/version.hpp>
#include <iostream>
#include <vector>
#include "abstract_plugin.h"

#if BOOST_VERSION >= 107600
#define boost_dll_import_symbol ::boost::dll::import_symbol
#else
#define boost_dll_import_symbol ::boost::dll::import
#endif

int main() {
    boost::shared_ptr<abstract_plugin> plugin =
        boost_dll_import_symbol<abstract_plugin>(
            "one", "plugin", boost::dll::load_mode::append_decorations);
    auto result = plugin->create_base();
    std::cout << "(1) saying hi by" << result.get() << "\n";
    result->say_non_virtual_hi();
    result->say_hi();

    std::cout << "(2) saying hi by" << result.get() << "\n";
    result->say_non_virtual_hi();
    result->say_hi();
    return 0;
}
