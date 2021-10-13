struct Foo {
    explicit operator bool() {
        return true;
    }
};

void bar([[maybe_unused]] int x) {
}

void baz(const Foo &) {
}

int main() {
    Foo f;
    if (f) { // if (f.operator bool()) { // Explicit!
    } else {
    }

    // while (cin) {} --> while (cin.operator bool()) {}

    // Safe bool idiom

    // [[maybe_unused]] int z1 = f;
    // [[maybe_unused]] int z2 = 10 + f;
    // bar(f);
}
