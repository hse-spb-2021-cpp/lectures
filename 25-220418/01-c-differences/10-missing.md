# Alternatives
* `*_cast` --> C-style-cast.
* `int a{}` --> `int a = 0;`
* namespaces --> prepend library name to all functions
* references --> pointers
* `bool` --> `int` + `0`/`1` OR `<stdbool.h>`
* `using` --> `typedef`
* `new`/`delete` --> `malloc`/`free` bytewise
* move/copy --> `memcpy`
* templates --> complicated macros

# Fully missing
* functions: overloading, default parameters
* `std::vector`
* exceptions
