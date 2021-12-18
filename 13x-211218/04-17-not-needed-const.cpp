// NOT NEEDED FOR EXAM
int main() {
    const int x = 10;
    const int *xptr = &x;
    xptr = nullptr;
    // *xptr = 10;

    int y = 20;
    int *const yptr = &y;
    // y = nullptr;
    *y = 30;
}
