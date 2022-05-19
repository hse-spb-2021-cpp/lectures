#include "a.h"

int main() {
    const int arr[] = {1, 2, 3};
    print_ints(const_cast<int*>(arr), sizeof arr / sizeof arr[0]);
}
