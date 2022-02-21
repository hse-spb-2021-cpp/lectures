#include <mutex>

struct list_node {
private:
    mutable std::mutex m;

    int data;
    list_node *next = nullptr;

public:
    list_node(int new_data, list_node *new_next) : data(new_data), next(new_next) {}

    void set_next(list_node *new_next) {
        std::unique_lock l(m);
        next = new_next;
    }

    list_node *get_next() {
        // https://twitter.com/Nekrolm/status/1487060735305957379
        // TOC-TOU is imminent!
        std::unique_lock l(m);
        return next;
    }
};

void append_after(list_node *x, int data) {
    x->set_next(new list_node(data, x->get_next()));
}
