#include <string>
#include <iostream>

struct Person { std::string name; };
struct Employee : virtual Person { std::string employer; };
struct Student : virtual Person { std::string group; };
struct MagicStudent : Employee, Student {};

/*
Somewhat real layout (although not guaranteed)
0                 8            40             48       80           112
+-----------------------------------------------------------------+
|  +------------------------+  +---------------------+ +--------+ |
|  | +---------+            |  | +---------+         | | Person | |
|  | | PersonV |            |  | | PersonV |         | | +name  | |
|  | | +person |            |  | | +person |         | +--------+ |
|  | +---------+            |  | +---------+         |            |
|  | Employee'              |  | Student'            |            |
|  |              +employer |  |              +group |            |
|  +------------------------+  +---------------------+            |
| MagicStudent                                                    |
+-----------------------------------------------------------------+
or:
0                 8        40           72
+-------------------------------------+
|  +---------------------+ +--------+ |
|  | +---------+         | | Person | |
|  | | PersonV |         | | +name  | |
|  | | +person |         | +--------+ |
|  | +---------+         |            |
|  | Student'            |            |
|  |              +group |            |
|  +---------------------+            |
| Student                             |
+-------------------------------------+
*/

int main() {
    std::cout << "sizeof(string) = " << sizeof(std::string) << "\n";
    std::cout << "sizeof(Person) = " << sizeof(Person) << "\n";
    {
        std::cout << "MagicStudent layout\n";
        MagicStudent ms;
        Employee &e = ms;
        Student &s = ms;
        Person &p = ms;
        std::cout << "    sizeof = " << sizeof(ms) << "\n";
        std::cout << "    this      = " << &ms << "\n";
        std::cout << "    Employee  = " << &e << "\n";
        std::cout << "    .employer = " << &ms.employer << "\n";
        std::cout << "    Student   = " << &s << "\n";
        std::cout << "    .group    = " << &ms.group << "\n";
        std::cout << "    Person    = " << &p << "\n";
        std::cout << "    .name     = " << &ms.name << "\n";
        [[maybe_unused]] MagicStudent &ms2 = static_cast<MagicStudent&>(p);
    }

    {
        std::cout << "Employee layout\n";
        Employee e;
        Person &p = e;
        std::cout << "    sizeof = " << sizeof(e) << "\n";
        std::cout << "    this      = " << &e << "\n";
        std::cout << "    .employer = " << &e.employer << "\n";
        std::cout << "    Person    = " << &p << "\n";
        std::cout << "    .name     = " << &e.name << "\n";
    }
}
