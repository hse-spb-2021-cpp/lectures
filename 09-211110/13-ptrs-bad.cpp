#include <iostream>
#include <vector>
#include <memory>
#include <utility>

struct Human {
    std::string first_name, last_name;  // Possibly wrong.

    Human(std::string first_name_, std::string last_name_)
        : first_name(std::move(first_name_))
        , last_name(std::move(last_name_)) {
    }
};

struct Student : Human {
    std::string group;  // Possibly wrong.

    Student(std::string first_name_, std::string last_name_, std::string group_)
        : Human(std::move(first_name_), std::move(last_name_))
        , group(std::move(group_)) {
    }
};

int main() {
    {
        std::vector<std::unique_ptr<Human>> people;
        people.push_back(std::make_unique<Human>("Egor", "Suvorov"));
    }
    {
        Human *h = new Human("Egor", "Suvorov");
        delete h;
    }
    {
        Student *s = new Student("Egor", "Suvorov", "BPM213S");
        delete s;
    }
    {
        Human *h = new Student("Egor", "Suvorov", "BPM213S");
        delete h;  // UB: ~Human()
        // delete static_cast<Student*>(h);  // Would be OK.
    }
}
