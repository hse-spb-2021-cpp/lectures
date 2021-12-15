// https://en.cppreference.com/w/cpp/language/storage_duration
#include <string>

// Linkage is a property of object/reference/function/type:
// 1. No linkage: only from the current scope
// 2. External linkage: visible in all translation units
// 3. Internal linkage: visible in the current translation unit only, but in all scopes. Independent between TUs.

int global_x;  // external linkage
void foo() {  // external linkage
}
struct Foo {  // external linkage
    int x;  // field, not an object/variable
    void foo() {  // external linkage
        int y;  // no linkage
        static int z;  // no linkage
    }
    static void bar() {  // external linkage
    }
};

namespace {  // Unnamed namespace changes 'external' to 'internal'
int global_y;  // internal linkage
void bar() {  // internal linkage
}
struct Bar {  // internal linkage
    int x;  // field, not an object/variable
    void foo() {  // internal linkage
        int y;  // no linkage
        static int z;  // no linkage
    }
    static void bar() {  // internal linkage
    }
};
}

// 'static' on global functions/variables is same as unnamed namespace
static int global_z;  // internal linkage
static void baz() {  // internal linkage
}

// special case: consts
const int TEN = 10;  // internal linkage
const std::string HELLO = "hello";  // internal linkage
