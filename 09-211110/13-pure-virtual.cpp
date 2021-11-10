#include <iostream>

struct Widget {
    virtual int width() const = 0;  // pure virtual => Widget is 'abstract'
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

void print_area(const Widget &w) {
    std::cout << w.area() << "\n";
}

int main() {
    Button btn("Click Me!");
    Image img(60, 70);
    print_area(btn);
    print_area(img);
    // Widget w;  // CE
    // new Widget();  // CE
}
