struct node {
    int data;
    node *prev, *next;
};

int main() {
    node a{10}, b{20}, c{30};

    a.prev = nullptr;  // NULL
    // *a.prev;
    // assert(a.prev != nullptr);

    a.next = &b;

    std::cout <<   b      .data << "\n";  // 20
    std::cout << (*a.next).data << "\n";  // 20
    std::cout <<   a.next->data << "\n";  // 20

    a.next = &c;
    std::cout << (*a.next).data << "\n";  // 30
    std::cout <<   a.next->data << "\n";  // 30
}
