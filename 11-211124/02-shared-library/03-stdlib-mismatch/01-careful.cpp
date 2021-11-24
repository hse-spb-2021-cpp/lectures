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
    // May be different for stdlibc++ and libc++
    // Other mismatches are possible: https://www.boost.org/doc/libs/master/doc/html/boost_dll/missuses.html
    // Solution: do everything C-style, will see later in the course.
    std::cout << "main: sizeof(std::string) = " << sizeof(std::string) << "\n";

    boost::shared_ptr<abstract_plugin> plugin =
        boost_dll_import_symbol<abstract_plugin>(
            "one", "plugin", boost::dll::load_mode::append_decorations);

    std::cout << "got from plugin: " << plugin->get_string() << "\n";
    plugin->print_string("hello from main");
    return 0;
}
