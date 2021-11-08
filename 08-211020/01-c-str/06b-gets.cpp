#include <cstdio>
#include <iostream>

int main() {
    const int MAX_LEN = 10;
    char buf[MAX_LEN + 1];
    gets(buf);  // DANGEROUS
    std::cout << "buf=|" << buf << "|\n";
}
