int x;

auto foo() {  // int
    return x;
}

decltype(auto) bar() {  // int
    return x;
}

decltype(auto) baz() {  // int&
    return (x);
}

int main() {
}
