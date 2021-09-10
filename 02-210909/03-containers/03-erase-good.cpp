#include <set>
#include <iostream>

int main() {
    {
        std::set<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (auto it = s.begin(); it != s.end(); ) {
            int x = *it;
            it++;

            if (x % 2 == 0) {
                s.erase(x);
            }
        }
        std::cout << s.size() << "\n";
    }
    {
        std::set<int> s{3, 1, 2, 4, 2};//, 100, 101, 102, 103, 104, 105, 106, 107};
        for (auto it = s.begin(); it != s.end(); ) {
            if (*it % 2 == 0) {
                auto it2 = it;
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
}
