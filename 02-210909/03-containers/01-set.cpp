#include <set>
#include <iostream>

int main() {
    {
        std::set<int> s{3, 1, 2, 4, 2};
        std::cout << s.size() << "\n";
        for (int x : s) {
            std::cout << " " << x;
        }
        std::cout << "\n";

        s.insert(10);
        s.erase(2);

        std::cout << s.count(3) << "\n";
        std::cout << s.count(33) << "\n";
    }

    {
        std::multiset<int> ms{3, 1, 2, 4, 2};
        std::cout << ms.size() << "\n";
        for (int x : ms) {
            std::cout << " " << x;
        }
        std::cout << "\n";

        ms.insert(10);
        ms.erase(2);  // O(log) + count(2)

        std::cout << ms.count(3) << "\n";  // O(log) + count(3)
    }

    {
        std::multiset<int> ms{3, 1, 2, 4, 2};
        std::cout << ms.size() << "\n";

        typename std::multiset<int>::iterator it = ms.begin();
        [[maybe_unused]] auto it2 = ms.begin();
        for (; it != ms.end(); it++) {
            std::cout << " " << *it;
        }
        std::cout << "\n";

        ms.erase(ms.find(2));
        std::cout << ms.size() << "\n";
        ms.erase(ms.find(2));
        std::cout << ms.size() << "\n";

        // Элемента не существует: find() == end()
        // erase(end()) - UB
        ms.erase(ms.find(2));  // UB
        std::cout << ms.size() << "\n";
    }
}
