#include <vector>
#include <iostream>

void foo(std::vector<int> a) {  // Создаст копию всего миллиона элементов, value-semantics
    // "Передача по значению"
    a.clear();  // vec не поменялся
}

void bar(std::vector<int> &a) {  // "Ссылка", reference semantics
    // "Передача по ссылке"
    a.clear();  // Меняется vec из main
    a = {1, 2, 3};  // Меняется vec из main
}

void baz(const std::vector<int> &a) {  // "Константная ссылка"
    std::cout << a.size() << "\n";
    std::cout << a[0] << "\n";
    a.clear();  // Ошибка компиляции
    a[0] = 10;  // Ошибка компиляции
}

int main() {
    std::vector<int> vec(1'000'000);
    foo(vec);
    // vec.size() == 1'000'000

    foo(std::vector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19});

    bar(vec);
    // vec == {1, 2, 3}
}
