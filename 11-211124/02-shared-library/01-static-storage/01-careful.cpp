#include <boost/dll/import.hpp>
#include <boost/version.hpp>
#include <iostream>
#include <vector>
#include "abstract_plugin.h"
#include "print_global_var.h"

#if BOOST_VERSION >= 107600
#define boost_dll_import_symbol ::boost::dll::import_symbol
#else
#define boost_dll_import_symbol ::boost::dll::import
#endif

int main() {
    boost::shared_ptr<abstract_plugin> plugin =
        boost_dll_import_symbol<abstract_plugin>(
            "one", "plugin", boost::dll::load_mode::append_decorations);
    // append_decorations converts 'one' into decorated name like 'libone.dll'
    // depending on the OS and the compiler

    std::cout << "main: global_var is at " << &global_var() << "\n";
    global_var() += 10;
    std::cout << "main: global_var = " << global_var() << "\n";
    std::cout << "main: ";
    print_global_var();

    plugin->foo();

    std::cout << "main: global_var = " << global_var() << "\n";

    // Reason:
    // There are actually two "C++ programs" running simultenously:
    // 1. `01-careful` the executable
    // 2. `one` the plugin
    // Each program has its own set of global variables, and is independently
    // compiled from a set of translation units. All standard rules regarding
    // globals and ODR violations act inside each individual program. There are
    // no "shared" variables between these two programs unless we create another
    // shared library (DLL) and put globals in there. CONCLUSION: do not use
    // global variables to communicate between an executable and a shared
    // library.

    // There may be globals in the standard library!
    // E.g. allocator or `std::cout` or something else:
    // https://docs.microsoft.com/en-us/cpp/c-runtime-library/potential-errors-passing-crt-objects-across-dll-boundaries?redirectedfrom=MSDN&view=msvc-160
    // However, on our systems the standard library is itself dynamically
    // linked, so there is only one instance. You can do it as well, look for
    // "link with dynamic library". Unnecessary in the lab.
}
