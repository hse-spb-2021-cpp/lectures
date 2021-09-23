struct my_vector {
    my_vector() {}
    explicit my_vector(int) {}
};

void print_vector([[maybe_unused]] const my_vector &vec) {
}

int main() {
    [[maybe_unused]] my_vector v1(10);
    // [[maybe_unused]] my_vector v2 = 10;
    // print_vector(10);
    [[maybe_unused]] my_vector v2 = static_cast<my_vector>(10);
    print_vector(static_cast<my_vector>(10));
}
