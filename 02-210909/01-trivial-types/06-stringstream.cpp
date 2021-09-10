#include <iostream>
#include <sstream>

int main() {
    {
        std::stringstream str;
        str << "123 456 789";

        int x, y, z;
        str >> x >> y;
        str >> z;
        
        std::cout << x << "\n";
        std::cout << y << "\n";
        std::cout << z << "\n";
    }
    {
        std::ostringstream s;  // Только <<
        s << 123 << " <-> " << 456;
        std::cout << s.str() << "\n";
    }
    {
        std::istringstream s("123 456\n789");  // Только >>
        int x, y, z;
        s >> x >> y;
        s >> z;
        std::cout << x << "," << y << "," << z << "\n";
    }
}
