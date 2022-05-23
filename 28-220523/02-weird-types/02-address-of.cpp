#include <memory>

// Simplified std::addressof
template<typename T> T* addressof(T& value) {
    return reinterpret_cast<T*>(&reinterpret_cast<const char&>(value));
}

void some_c_api(const void*);
template<typename T>
void CallSomeCApi(const T &value) {
    some_c_api(static_cast<const void*>(&value));
    // some_c_api(std::addressof(value));
}

struct S { int operator&() const { return 7; } };  // wtf, meme: https://habr.com/ru/post/203276/

int main() {
    S s;
    CallSomeCApi(10);  // ok
    CallSomeCApi(s);   // compilation error with &
}
