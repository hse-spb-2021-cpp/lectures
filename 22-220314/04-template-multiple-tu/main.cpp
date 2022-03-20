#include "print.h"

void foo();

int main() {
    print(1);
    print(1.23);
    my_template<int>{}.foo();
    foo();
}
