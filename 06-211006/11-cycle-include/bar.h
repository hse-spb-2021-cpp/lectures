#ifndef BAR_H_
#define BAR_H_

#include "foo_fwd.h"

struct Bar {
    Foo *f;
};

void bar_do_something(Foo, Bar);

#endif  // BAR_H_
