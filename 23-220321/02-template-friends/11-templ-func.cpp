template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (4) For all T: for all U: foo(MyTemplate<U>&, MyTemplate<void>&) is a friend MyTemplate<T>
    template<typename U>
    friend void foo(MyTemplate<U> &, MyTemplate<void> &);

    // (5) For all T: generate an independent template non_templ_friend<U>(MyTemplate<T>, MyTemplate<U>) which is a friend of MyTemplate<T> for any U.
    template<typename U>
    friend void bar(MyTemplate &val, MyTemplate<U> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile when T != U because it's not a friend of MyTemplate<T>. Both GCC and Clang agree.
    }
};

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    foo(val1, weird);
    foo(val2, weird);

    bar(val1, val1);
    // bar(val1, weird);  // T=int, U=void
}
