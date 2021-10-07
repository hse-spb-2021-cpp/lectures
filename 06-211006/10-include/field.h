// Alternative: '#pragma once', not in standard, but all major compilers support it.

#ifndef FIELD_H_  // Include guards
#define FIELD_H_

namespace field {
struct Field {
    int width, height;

    int area() const;
};

Field create_field(int width, int height);
}  // namespace field

#endif  // FIELD_H_
