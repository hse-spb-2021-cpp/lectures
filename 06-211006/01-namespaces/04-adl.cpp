// Argument-Dependent Lookup aka Koenig Lookup

namespace ns {
struct Foo {};

void do_something() {}
void do_something(Foo) {}
bool operator==(const Foo&, const Foo&) { return true; }
};

int main() {
    // do_something();
    ns::do_something();

    // Foo f;
    ns::Foo f;
    do_something(f);  // unqualified name lookup, ADL enabled

    // f == f;
    // operator==(f, f)
    // ns::operator==(f, f);

    // Example:
    // getline(std::cin, str)
    // Better: std::getline
    //
    // std::vector<int> v{1, 2, 3};
    // sort(v.begin(), v.end());  // v.begin() ~ std::vector<int>::iterator ~(?) int*
    // Better: std::sort
}
