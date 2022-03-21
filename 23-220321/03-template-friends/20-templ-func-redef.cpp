template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // For all T: make a new template<typename U> void foo().
    // They coincide and redefine each other => compilation error.
    template<typename U>
    friend void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;
    }
};

int main() {
    MyTemplate<int> a;
    MyTemplate<void> c;
    foo(a, c);
}