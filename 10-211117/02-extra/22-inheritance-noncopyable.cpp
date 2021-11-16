struct noncopyable {  // boost::noncopyable
    noncopyable() = default;
    noncopyable(const noncopyable &) = delete;
    noncopyable(noncopyable &&) = delete;
    noncopyable &operator=(const noncopyable &) = delete;
    noncopyable &operator=(noncopyable &&) = delete;
};

struct Foo : private noncopyable {};

int main() {
    Foo f;
    // noncopyable &n = f;  // WTF, 'private' prevents that.
}
