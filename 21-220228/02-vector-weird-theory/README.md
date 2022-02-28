It's close to impossible to implement `std::vector` in standard C++ on three accounts:

1. You may need to "launder" memory if you've reused it for a new object which has const/reference fields.
   `std::launder` may help, but it's weird and obscure: https://miyuki.github.io/2016/10/21/std-launder.html
2. Special case (not related to `vector`): vptr looks like const fields.
3. "Raw memory" (e.g. by an allocator) is not the same as "Array of `T`".
   Hence you cannot do pointer arithmetics with `T*` pointing inside "raw memory".
   But C++ standard requires `&v[0] + 2 == &v[2]`, so the use has to be able to do pointer arithmetics.
   This is presumably fixed in C++20 with no additional code.

I expect no practical implications.



