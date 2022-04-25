#ifdef __cplusplus
extern "C" {
#endif

int foo(void);  // Remember to say "no arguments" in C! It's compatible with C++
int my_main();  // Bad style.

// There are other incompatibilities: e.g. default arguments, macros instead of consts, you name it...

#ifdef __cplusplus
}
#endif
