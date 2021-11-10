Careful:

* `00b-special-operators.cpp` is a separate thing, may be excess (only needed for slicing)
* Maybe `bad-c-cast` is also a weird detail, maybe remove under time pressure?


`03-casts`:

* Extract bar() to a separate file and:
    * Leave a comment "Show how to prevent slicing"
       ```c++
        // Preventing slicing
        /*
        Base(const Base &) = delete;
        Base(Base &&) = delete;
        Base &operator=(const Base &) = delete;
        Base &operator=(Base &&) = delete;
        */
        ```
    * Show that `b.x` is correctly copied from `d.x`
* Add `ostream&` example somewhere around virtual (or earlier?)

`1x`:

* Use a function call instead of `Base &db = ...`
