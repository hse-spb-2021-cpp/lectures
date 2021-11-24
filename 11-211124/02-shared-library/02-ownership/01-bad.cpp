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

std::unique_ptr<base> load_from_plugin() {
    boost::shared_ptr<abstract_plugin> plugin =
        boost_dll_import_symbol<abstract_plugin>(
            "one", "plugin", boost::dll::load_mode::append_decorations);
    auto result = plugin->create_base();
    std::cout << "(1) saying hi by" << result.get() << "\n";
    result->say_non_virtual_hi();
    result->say_hi();
    return result;
}

int main() {
    std::unique_ptr<base> result = load_from_plugin();
    // OOPS: the DLL is already unloaded, all allocated data is freed.
    // 'result' is available, but its virtual tables are not.
    std::cout << "(2) saying hi by" << result.get() << "\n";
    result->say_non_virtual_hi();
    result->say_hi();
    return 0;
}
