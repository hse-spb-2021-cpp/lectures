#include <vector>
#include <utility>

typedef std::vector<int> vi;
using pii = std::pair<int, int>;

int main() {
    vi v1(10);
    std::vector<int> &v2 = v1;

    pii p1(10, 20);
    std::pair<int, int> &p2 = p1;
}
