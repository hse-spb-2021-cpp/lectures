#include <vector>

// https://en.cppreference.com/w/cpp/language/initialization
// https://habr.com/ru/company/jugru/blog/469465/

struct Foo {
    int default_initialized_int;   // not initialized
    std::vector<int> default_initialized_vector;  // default-constructed
    int di_int_1{};  // value-initialized: 0
    int di_int_2;

    Foo() : di_int_2{} {}
};

void foo(double) {
}

void bar(std::pair<int, int>) {
}

int main() {
    int default_initialized_int;  // not initialized
    std::vector<int> default_initialized_vector;  // default-constructed: empty
    Foo default_f;  // default-constructed: '*_int' not initialized, '*_vector' default-constructed

    int value_initializated_int{};  // value initialization: 0
    std::vector<int> value_initializated_vector{};  // default-constructed: empty
    Foo value_f{};   // default-constructed: '*_int' not initialized, '*_vector' is empty

    auto value_int_1 = int();  // value initialization: 0
    auto value_vec_1 = std::vector<int>();
    auto value_foo_1 = Foo();

    auto value_int_2 = int{};  // value initialization: 0
    auto value_vec_2 = std::vector<int>{};
    auto value_foo_2 = Foo{};

    // Direct initialization
    std::vector<int> direct_vec_1(10);
    auto direct_vec_2 = static_cast<std::vector<int>>(10);
    std::vector<int> direct_vec_3(10, 123);
    std::vector<int>(10);  // size() == 10

    // Copy initialization
    std::vector<int> copy_vec_1 = direct_vec_1;
    // bigint x = 55;
    // std::vector<int> copy_vec_2 = 20;  // constructor is explicit
    foo(10);
    // return something;

    // Direct list initialization
    std::vector<int> direct_list_vec{1, 2, 3};
    std::vector<int>{10};  // size() == 1
    // return std::vector<int>{1, 2, 3};

    // Copy list initialization
    std::vector<int> direct_list_vec = {1, 2, 3};
    bar({1, 2});
    // return {1, 2, 3};

    // Important:
    // 1. Direct vs copy: explicit vs implicit.
    // 2. Do not default-initialization: always initialize fundamental types.
}
