#include <iostream>
#include <vector>

int main() {
    // int arr[10];
    // int arr[n];  // VLA, variable-length array, extension
    // static int arr[MAXN];

    std::vector<int> v;
    std::cout << v.size() << " " << v.empty() << "\n";
    v.push_back(10);
    v.push_back(20);
    std::cout << v[0] << " " << v[1] << "\n";

    v = {1, 2, 3, 4};
    std::cout << v.size() << "\n";

    std::vector<int> v2 = {5, 6, 7};
    v2.resize(100);
    std::cout << v2.size() << " " << v2[50] << "\n";
    v2.resize(1);
    std::cout << v2.size() << " " << v2[0] << "\n";

    std::vector<int> v3(100, 10);
    std::cout << v3[50] << "\n";

    std::vector<std::vector<int>> vec_2d(10, std::vector<int>(20, 'x' /* 120 */));
    std::cout << vec_2d.size() << "\n";
    std::cout << vec_2d[5].size() << "\n";
    std::cout << vec_2d[5][15] << "\n";
    vec_2d[5][15] = 500;
    std::cout << vec_2d[5][15] << "\n";
    std::cout << vec_2d[6][15] << "\n";

    vec_2d[6].clear();  // resize(0);
    std::cout << vec_2d[0].size() << " vs " << vec_2d[6].size() << "\n";
    vec_2d.clear();
}
