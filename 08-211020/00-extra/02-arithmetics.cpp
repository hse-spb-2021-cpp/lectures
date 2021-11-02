#include <cassert>
#include <cstddef>

int main() {
    int data[]{10, 20, 30, 40};
    
    int *p1 = &data[0];  // taking address of the first element
    assert(*p1 == 10);

    int *p2 = data;  // array-to-pointer decay
    assert(p2 == p1);
    assert(*p2 == 10);

    // Arithmetics just like iterators
    int *q = p1 + 2;
    assert(q == &data[2]);
    assert(data + 2 == &data[2]);
    assert(*q == 30);

    int *r = q;
    r--;
    assert(r == &data[1]);
    assert(*r == 20);

    int x = *r--;  // *(r--)
    assert(x == 20);
    assert(data[1] == 20);
    assert(data[0] == 10);
    assert(r == &data[0]);
    assert(*r == 10);

    std::ptrdiff_t diff = r - q;
    assert(diff == -2);
    assert(&data[0] - &data[2] == -2);
}
