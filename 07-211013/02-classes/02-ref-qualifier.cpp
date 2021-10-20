#include <assert.h>
#include <vector>

class stack {
    std::vector<int> data;

public:
    void push(int x) & {  // ref-qualifier
        data.push_back(x);
    }

    [[nodiscard]] int get() const {
        assert(!data.empty());
        return data.back();
    }

    int pop() & {  // ref-qualifier
        assert(!data.empty());
        int result = data.back();
        data.pop_back();
        // this->data == data
        return result;
    }
};

stack foo() {
    stack s;
    s.push(1);
    s.push(2);
    return s;
}

int main() {
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.get() == 3);
    assert(s.pop() == 3);
    assert(s.pop() == 2);
    assert(s.pop() == 1);

    assert(foo().get() == 2);
    assert(foo().pop() == 2);
    foo().push(10);

    std::vector<int>{1, 2, 3}.push_back(40);
    std::vector<int>{1, 2, 3} = std::vector{4, 5, 6};

    // bigint a;
    // (a++) = 10;

    // int b;
    // b++ = 10;
}
