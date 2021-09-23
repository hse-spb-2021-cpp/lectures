#include <cassert>

struct ratio {
    // denom != 0
    int num;
    int denom;

    ratio() : num(0), denom(1) {}
    ratio(int value) : num(value), denom(1) {}
    ratio(int num_, int denom_) : num(num_), denom(denom_) {
        assert(denom != 0);
    }
    explicit operator double() {
        return num * 1.0 / denom;
    }
};

int main() {
    ratio r;
    // r = {0, 0};
    r.denom = 0;
}
