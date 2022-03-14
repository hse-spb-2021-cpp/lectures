See 14-220110/02-templates

Recall:
* "Instantiation"
* Class instantiation
* Method/function instantiation

Compare templates (static polymorphism) with inheritance (dynamic polymorphism).

```
template<typename C>
bool is_empty(const C &c) {
    return c.empty();  // Which .empty() to call is determined in compile time
                       // 'Static'/'compile-time' polymorphism
}

struct Base { virtual void foo() = 0; }
bool call_foo(Base &b) {
    b.foo();  // Which .foo() to call is determined in run time
              // 'Dynamic'/'run-time' polymorphism
}
```
