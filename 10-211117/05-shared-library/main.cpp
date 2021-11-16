#include <boost/dll/import.hpp> // for import_alias
#include <boost/filesystem/path.hpp>
#include <iostream>
#include <vector>
#include "abstract_plugin.h"

namespace plugins_demo {
int main() {
    namespace fs = boost::filesystem;

    std::vector<boost::shared_ptr<plugins_demo::abstract_plugin>> plugins;
    for (auto &f : fs::directory_iterator(fs::path("plugins/"))) {
        std::cout << "Loading from " << f << "\n";
        plugins.emplace_back(boost::dll::import_symbol<plugins_demo::abstract_plugin>(
            f.path(),
            "plugin"
        ));
        // TODO: dll::load_mode::append_decorations
    }

    for (auto &plugin : plugins) {
        std::cout << plugin->name() << "->calculate(1.5, 1.5) == " << plugin->calculate(1.5, 1.5) << std::endl;
    }
    return 0;
}
}  // namespace plugins_demo

int main() {
    return plugins_demo::main();
}
