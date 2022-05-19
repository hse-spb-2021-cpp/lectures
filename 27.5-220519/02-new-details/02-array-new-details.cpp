#include <iostream>

int main() {
    int *ints;

    ints = new int[0];  // Non-null, may fail
    std::cout << ints << "\n";  // Non-null (not sure if required or not)
    delete[] ints;

    ints = new int[5];  // default-initialization: uninitialized;
    std::cout << ints[0] << "\n";  // UB
    delete[] ints;

    ints = new int[5]{};  // value-initialization
    std::cout << ints[0] << "\n";
    delete[] ints;

    int x = 5;
    ints = new int[x]{1, 2};  // copy-initialization + value-initialization
                              // std::bad_array_new_length if x < 2
    std::cout << ints[0] << " " << ints[1] << " " << ints[2] << "\n";
    delete[] ints;

    // Do not do placement new[]
    // https://github.com/Nekrolm/ubbook/blob/master/pointer_prominence/array_placement_new.md
    // https://stackoverflow.com/questions/15254/can-placement-new-for-arrays-be-used-in-a-portable-way
}
