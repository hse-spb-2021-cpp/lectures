#include <iostream>

void foo() {
    std::cout << "foo global\n";
}

void some_global() {
    std::cout << "some_global\n";
}

namespace ns1 {
void bar() {
    std::cout << "ns1::bar()\n";
}

namespace ns2 {
void bar() {
    std::cout << "ns1::ns2::bar\n";
}
}  // namespace ns2

namespace ns3 {
void botva_ns3() {
    std::cout << "botva_ns3()\n";
}
}  // namespace ns3

namespace ns3::ns4 {
namespace ns1 {  // ns1::ns3::ns4::ns1
}

void baz() {
    botva_ns3();  // unqualified name lookup for 'botva_ns3'
    ns2::bar();  // unqualified name lookup for 'ns2', qualified name lookup bar()
    // ns2::foo();  // compilation error: no 'foo' inside 'ns2'
    // ns1::ns2::bar();  // thinks that 'ns1' is 'ns1::ns3::ns4::ns1', 'n2' not found
    ::ns1::ns2::bar();
}
}  // namespace ns3::ns4
}  // namespace ns1

int main() {
    ns1::ns3::ns4::baz();
}
