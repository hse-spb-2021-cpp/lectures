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

    std::cout << "main: global_var is at " << &global_var() << "\n";
    global_var() += 10;
    std::cout << "main: global_var = " << global_var() << "\n";

    plugin->foo();

    std::cout << "main: global_var = " << global_var() << "\n";

    // There may be globals in the standard library!
    // E.g. allocator or `std::cout` or something else: https://docs.microsoft.com/en-us/cpp/c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries?redirectedfrom=MSDN&view=msvc-160
    // However, on our systems the standard library is itself dynamically linked, so there is only one instance.
    // You can do it as well, look for "link with dynamic library". Unnecessary in the lab.
}
