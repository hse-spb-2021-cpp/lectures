#ifndef FOO_H_
#define FOO_H_

#include "bar.h"
#include "foo_fwd.h"

struct Foo {
    Bar b{this};
};

void foo_do_something(Foo, Bar);

#endif  // FOO_H_
