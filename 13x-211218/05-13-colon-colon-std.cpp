#include <vector>

namespace ns1 {
    void foo() {
        std::vector<int> v;
    }
}

namespace ns2 {
    namespace std {}
    void foo() {
        // Say hello to lab03-mytest
        // std::vector<int> v;
        ::std::vector<int> v;
    }
}

int main() {
    std::vector<int> v;
}
