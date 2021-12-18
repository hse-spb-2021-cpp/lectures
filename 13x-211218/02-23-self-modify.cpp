#include <iostream>

struct Ratio {
   int num, denom;

   Ratio &operator/=(const Ratio &other) {
       // &other == this
       // {2, 3}
       num *= other.denom;
       // {6, 3}
       denom *= other.num;
       // {6, 18}
       return *this;
   }
};

int main() {
    Ratio r{2, 3};
    r /= r;
    std::cout << r.num << " " << r.denom << "\n";
}
