#include <vector>

void foo(int a, int &b, const std::vector<int> &v) {
    a++;
    b++;
}

int main() {
    int x = 50, y = 60;
    foo(x, y, {1, 2, 3});
    /*
    {
        int a = x;  // copy initialization
        int &b = y;  // copy initialization
        const std::vector<int> &vec = {1, 2, 3};
        a++;
        b++;
    }
    */
    std::vector<int> vec{1, 2, 3};
    for (int a : vec) {}
    for (int &a : vec) {}
    for (const int &a : vec) {}
}
