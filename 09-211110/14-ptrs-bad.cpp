#include <iostream>
#include <memory>
#include <vector>

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
    {
        std::vector<std::unique_ptr<Widget>> widgets;
        widgets.emplace_back(std::make_unique<Button>("Click Me!"));
        widgets.emplace_back(std::make_unique<Image>(60, 70));
        for (const auto &w : widgets) {
            std::cout << w->area() << "\n";
        }
    }
    {
        Button *b = new Button("Click me!");
        delete b;
    }
    {
        Image *i = new Image(60, 70);
        delete i;
    }
    {
        Widget *w = new Button("Click me!");
        delete w;  // UB: ~Widget()
        // delete static_cast<Button*>(w);  // Would be OK.
    }
}
