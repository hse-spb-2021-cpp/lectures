int main() {
    auto fib = [&](int n) {
        if (n <= 1) return n;
        // Compilation error: type of lambda depends on its captures => cannot capture fib.
        return fib(n - 1) + fib(n - 2);
    };
}
