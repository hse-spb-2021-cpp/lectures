Добавили между типом и аргументами `(*)`, получили `void(*)(int)`.

```c++
char foo(int);
// ....
auto x = [](int val) -> char { return val; };
auto y = [&](int val) -> char { return val; };
char (*func1)(int) = &foo;  // Ок.
char (*func2)(int) = foo;   // Ок, функция неявно преобразуется в указатель на себя.
char (*func3)(int) = x;     // Ок: лямбда без захвата — почти свободная функция.
char (*func4)(int) = y;     // Не ок: лямбда с захватом должна знать своё состояние.
```

А ещё функции и данные могут вообще в совсем разной памяти лежать:
```c++
void *x = static_cast<void*>(&foo);  // Ошибка компиляции.
```
* Но Linux пофиг: там какие-то функции возвращают `void*` вместо указателей на функции.

Между собой указатели на функции несовместимы:
```c++
void (*func5)() = func4;
void (*func6)(int) = func4;
```
