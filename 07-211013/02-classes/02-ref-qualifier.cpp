#include <assert.h>
#include <vector>

class Stack {
    std::vector<int> data;

public:
    void push(int x) & {
        data.push_back(x);
    }

    int get() const {
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

Stack foo() {
    Stack s;
    s.push(1);
    s.push(2);
    return s;
}

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    assert(s.get() == 3);
    assert(s.pop() == 3);
    assert(s.pop() == 2);
    assert(s.pop() == 1);

    foo().push(10);
}
