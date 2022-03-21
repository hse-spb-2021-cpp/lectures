template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (1) Non-template declaration
    friend void simple_func();

    // (2) For all T: generate an independent non-template non_simple_func(MyTemplate<T>&) declaration, impossible to define outside the class in general.
    // Warning.
    friend void non_simple_func(MyTemplate&);

    // (3) For all T: generate an independent non-template non_templ_friend(MyTemplate<T>, MyTemplate<void>) which is a friend of MyTemplate<T>.
    friend void non_templ_friend(MyTemplate &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile, but GCC compiles it anyway. Clang does not.
    }
};

void simple_func() {
    MyTemplate<int> val1;
    val1.x = 10;
}

// Template non_simple_func<T>(), does not correspond to a non-template declaration inside MyTemplate.
template<typename T>
void non_simple_func(MyTemplate<T> &val) {
    // val.x = 10;
}

// Non-template non_simple_func
void non_simple_func(MyTemplate<int> &val) {
    val.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    non_simple_func(val1);  // Calls global function, ok
    // non_simple_func(val2);  // Calls global function by its friend declaration, undefined reference.
    non_simple_func<int>(val1);  // Attempts to call the template function, it is not a friend.

    MyTemplate<int> val1b;
    // non_templ_friend(val1, val1b);  // val1b is not <void>
    non_templ_friend(val1, weird);
    non_templ_friend(val2, weird);
}
