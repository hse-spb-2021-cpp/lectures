```c++
void foo(int x);
char foo(char x);
// ....
TD<decltype(&foo)>{};  // Ошибка компиляции: какую перегрузку выбрать decltype?
```

Вывод: у `&foo` нет типа (примерно как у `{1, 2, 3}`).

```c++
void (*func1)(int)  = &foo;  // Если в точности указать тип, то перегрузка разрешится.
char (*func2)(char) = &foo;
```

Вызывает проблемы в шаблонных функциях или с `auto`:
```c++
template<typename Fn> void bar(Fn fn) { fn(10); }
// ....
bar(&foo);  // no matching function for call to 'bar(<unresolved overloaded function>)'
bar(static_cast<void(*)(int)>(&foo));  // Ок.
bar([](int x) { return foo(x); });     // Ок, у лямбды фиксированный параметр.
```
