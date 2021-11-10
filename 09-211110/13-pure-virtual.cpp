#include <iostream>

struct Widget {
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const {
        return width() * height();
    }
};

struct Button : Widget {
    std::string label;

    Button(std::string label_) : label(std::move(label_)) {}

    int width() const override {
        return 10 + 8 * label.length();
    }

    int height() const override {
        return 10 + 12;
    }
};

struct Image : Widget {
    int w, h;

    Image(int w_, int h_) : w(w_), h(h_) {}

    int width() const override {
        return w;
    }

    int height() const override {
        return h;
    }
};

int main() {
    Button btn("Click Me!");
    Image img(60, 70);
    std::cout << btn.area() << "\n";
    std::cout << img.area() << "\n";
}
