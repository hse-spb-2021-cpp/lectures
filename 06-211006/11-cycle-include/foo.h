#ifndef FOO_H_
#define FOO_H_

#include "foo_fwd.h"
#include "bar.h"

struct Foo {
    Bar b{this};
};

void foo_do_something(Foo, Bar);

#endif  // FOO_H_
