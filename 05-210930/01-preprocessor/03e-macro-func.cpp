#define FOO(a, b) (a b)
#define BAR(a, b) FOO(a, a) FOO(b, b)
#define BAZ(a, b) BAR(a, a) BAR(b, b)

// Please do not try FOO(BAR) at home.
// Extra reading: Boost::PP (preprocessor).

int main() {
    BAZ(1 + 1, wow botva);
}
