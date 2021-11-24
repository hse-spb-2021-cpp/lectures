#include <string>
#include <iostream>

// Diamond problem.
struct Person { std::string name; };
struct Employee : virtual Person { std::string employer; };
struct Student : virtual Person { std::string group; };
struct MagicStudent : Employee, Student {
    MagicStudent() : Person(), Employee(), Student() {}
};

int main() {
    MagicStudent ms;
    ms.name = "Egor";

    Person &p = ms;
    Employee &e = ms;
    Student &s = ms;
    std::cout << &ms << "\n";
    std::cout << &p << "\n";
    std::cout << &e << "\n";
    std::cout << &s << "\n";
    std::cout << sizeof(std::string) << "\n";
    std::cout << sizeof(MagicStudent) << "\n";

    {
        std::cout << "=====\n";
        Employee e;
        std::cout << sizeof(Person) << "\n";
        std::cout << sizeof(Employee) << "\n";
        std::cout << &e << "\n";
        std::cout << &static_cast<Person&>(e) << "\n";
        std::cout << &e.name << "\n";
        std::cout << &e.employer << "\n";
    }
}
