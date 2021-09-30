order of evaluation: https://en.cppreference.com/w/cpp/language/eval_order
&&, ||, , short-circuit unless overloaded
?:

return type deduction (auto; multiple returns)

lambda captures
operator() and lambdas
dangling reference

const overloading
escaping in string literals

range-based for with references

typedef/using

char* is a C-style string
conversion rules: not more than one user-defined conversion

no default constructor => needs member-initialization list
delegating constructors

[[nodiscard]]
[[maybe_unused]]

ADL + std::swap
std::optional
std::tuple  vs std::pair
std::as_const
switch + [[fallthrough]]

istreams hierarchy
iterators hierarchy

// namespaces
ADL (// do not use) : operator<<, getline
https://en.cppreference.com/w/cpp/language/adl

:: vs std::
namespace {} and namespace a::b {}
