int main() {
#ifdef __GNUC__  // Everything is very compiler-specific, see doctest.h for an example
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-variable"
#endif
    /* [[maybe_unused]] */ int x = 10;
#ifdef __GNUC__
    #pragma GCC diagnostic pop
#endif
}
