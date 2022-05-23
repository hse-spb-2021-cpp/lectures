template<typename> struct TD;

int& foo();
int&& bar();

int main() {
    int x = 10;
    int &y = x;

    //TD<decltype(10)>{};  // int
    //TD<decltype(10 + 20)>{};  // int
    //TD<decltype(x)>{};  // int
    //TD<decltype(y)>{};  // int&
    //TD<decltype(y + 20)>{};  // int
    //TD<decltype(y + 0)>{};  // int
    //TD<decltype(  (y + 0)  )>{};  // int
    //TD<decltype(  (x + 0)  )>{};  // int
    // TD<decltype(  (x)  )>{};  // int& ?????

    // decltype() has two modes:
    // 1. decltype(expression)
    TD<decltype(10)>();  // int
    TD<decltype( (x) )>();  // int&
    TD<decltype( (y) )>();  // int&
    TD<decltype( x + 20 )>();  // int
    TD<decltype( foo() )>();  // int&
    TD<decltype( bar() )>();  // int&&
    // Returns depending on value category: T (prvalue), T& (lvalue), T&& (xvalue)

    // 2. decltype(name) - a variable/field/argument with no parens
    TD<decltype(x)>();  // int
    TD<decltype(y)>();  // int&
    // Returns: the declaration of `name`
}
