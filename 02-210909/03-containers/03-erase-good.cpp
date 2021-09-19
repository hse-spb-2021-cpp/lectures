#include <set>
#include <iostream>

int main() {
    {
        std::set<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (auto it = s.begin(); it != s.end(); ) {
            int x = *it;
            it++;

            // 1 2 3 4
            //     ^
            if (x % 2 == 0) {
                s.erase(x);
            }
            // 1   3 4
            //     ^
        }
        std::cout << s.size() << "\n";
    }
    {
        std::multiset<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (auto it = s.begin(); it != s.end(); ) {
            if (*it % 2 == 0) {
                auto it2 = it;  // Или std::next()
                it2++;
                s.erase(it);
                it = it2;
            } else {
                it++;
            }
        }
        std::cout << s.size() << "\n";
    }
    {
        std::set<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (auto it = s.begin(); it != s.end(); ) {
            if (*it % 2 == 0) {
                it = s.erase(it);
            } else {
                it++;
            }
        }
        std::cout << s.size() << "\n";
    }
    // std::remove_if
    // C++20: ranges
}
