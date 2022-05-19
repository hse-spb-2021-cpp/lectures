// pimpl ~ pointer to implementation

// Before 
// a.h
class very_complex_class {
private:
    int a, b, c, d, e, f;

public:
    void make_everyone_happy();
    void make_everyone_sad();
};
// a.cpp
void very_complex_class::make_everyone_happy() {
    // ....
}

// After
// a.h
struct very_complex_class_impl;
class very_complex_class {
private:
    std::unique_ptr<very_complex_class_impl> pImpl;

public:
    very_complex_class_impl();
    void make_everyone_happy();
    void make_everyone_sad();
};
// a.cpp
struct very_complex_class_impl {
    int a, b, c, d, e, f;
    void make_everyone_happy();
    void make_everyone_sad();
};
very_complex_class_impl::very_complex_class_impl()
    : pImpl(new very_complex_class_impl()) {}
void very_complex_class::make_everyone_happy() {
    return pImpl->make_everyone_happy();
}
void very_complex_class::make_everyone_sad() {
    return pImpl->make_everyone_happy();
}
void very_complex_class_impl::make_everyone_happy() {
    // ....
}
void very_complex_class_impl::make_everyone_happy() {
    // ....
}
