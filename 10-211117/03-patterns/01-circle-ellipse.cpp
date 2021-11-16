// https://isocpp.org/wiki/faq/proper-inheritance

// OK
struct Ellipse {
    virtual int width();
    virtual int height();
};

struct Circle : Ellipse {
    virtual int radius();
};

// WTF
struct Circle {
    virtual int radius();
};

struct Ellipse : Circle {
    virtual int radius() {
        ? ? ? ? ? ? ? ? ? ? ? ? ?
    }
    virtual int width();
    virtual int height();
};

// WTF
struct Ellipse {
    virtual void setWidth(int w);
    virtual void setHeight(int h);
};

void foo(Ellipse &e) {
    // LSP violation:
    // https://ru.wikipedia.org/wiki/%D0%9F%D1%80%D0%B8%D0%BD%D1%86%D0%B8%D0%BF_%D0%BF%D0%BE%D0%B4%D1%81%D1%82%D0%B0%D0%BD%D0%BE%D0%B2%D0%BA%D0%B8_%D0%91%D0%B0%D1%80%D0%B1%D0%B0%D1%80%D1%8B_%D0%9B%D0%B8%D1%81%D0%BA%D0%BE%D0%B2
    e.setWidth(10);
    e.setHeight(20);
    assert(e.width() == 10);
    assert(e.height() == 20);
}

struct Circle : Ellipse {
    virtual void setWidth() {
        .....
    }
    void setRadius(int r);
};

// OK
struct Circle {
    virtual void setRadius(int r);
};

struct Ellipse : Circle {
    virtual void setRadius(int r) {
        setWidth(r);
        setHeight(r);
    }
    virtual void setWidth(int w);
    virtual void setHeight(int h);
};
