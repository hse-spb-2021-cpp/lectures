02: highlight `#include "bigint.inc.cpp"` vs multiple TUs, otherwise problems appear at 10.
03-default-args-ub should be after 04-return-value
10: split in two: without guards, with guards (Foo is used by both Bar/Baz)
    simplify.
    lots of confusion about `#include`
