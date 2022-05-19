#include <list>
#include <string>

struct process1 {
    int pid;
    std::string command;
    int user_id;
};

void foo() {
    std::list<process1> processes;
    std::list<process1*> waiting_for_io;
}

struct node_entry {
    node_entry *prev, *next;
};
void link(node_entry *a, node_entry *b);

struct process2 {
    int pid;
    std::string command;
    int user_id;
    node_entry all_processes;
    node_entry waiting_for_io;
};

void bar() {
    process2 a, b, c;
    link(&a.all_processes, &b.all_processes);
    link(&b.all_processes, &c.all_processes);
}

boost::intrusive_ptr ~ boost::shared_ptr, but without dynamic memory allocation
