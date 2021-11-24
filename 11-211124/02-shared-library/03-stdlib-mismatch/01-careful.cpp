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
    // May be different for stdlibc++ and libc++.
    // Other mismatches are possible:
    // https://www.boost.org/doc/libs/master/doc/html/boost_dll/missuses.html
    std::cout << "main: sizeof(std::string) = " << sizeof(std::string) << "\n";

    boost::shared_ptr<abstract_plugin> plugin =
        boost_dll_import_symbol<abstract_plugin>(
            "one", "plugin", boost::dll::load_mode::append_decorations);

    // Code below may crash if there is ABI (Application Binary Interface)
    // incompatibility. E.g. if the plugin assumes `std::string` to have one
    // size/layout/invariants and we do it in the other way. ABI
    // incompatibilities are possible even if the code is API (Application
    // Programming Interface) compatible, like here: we use std::string with the
    // same interface.
    //
    // Solutions:
    // 1. Do everything C-style, will see later in the course. C ABI is much
    //    easier.
    // 2. Be very careful with ABI compatibility: ensure you use the same
    //    compiler with the same flags.
    // 3. Be very careful with ABI compatibility: ensure you know what ABI your
    //    compiler uses and use it consistently.
    //    E.g. it's typical to have Boost compiled with different Visual Studio
    //    ABIs. Latest Visual C++ ABIs are MSVC 14.0 (VS 2015), MSVC 14.1 (VS
    //    2017), MSVC 14.2 (VS 2019), see
    //    https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B#Internal_version_numbering
    //    Same for Python: if you want to develop a Python module, you have to
    //    know what is the expected ABI by specific Python on your machine.
    std::cout << "got from plugin: " << plugin->get_string() << "\n";
    plugin->print_string("hello from main");
    return 0;
}
