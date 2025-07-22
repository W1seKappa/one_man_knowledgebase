# one_man_knowledgebase

## Computer science


## C++

### Trailing return type

```cpp

auto foo(int x, int y) -> int;
int foo2(int x, int y);
```

Это абсолютно равнозначные записи и смысла так писать нет, однако, если тип необходимо вывести из аргументов функции, то можно использовать decltype в этом подходе

```cpp
auto foo(int x, int y) -> decltype(x + y);
```

Тогда тип возвращаемое значения будет выведен из типа результа операции, тут семантика в том, что после объявления принимаемых аргументов функции они становяться доступны для компилятора.

Но в С++ 14 появилась запись
```cpp
decltype(auto) foo(int x, int y) {
    return x + y;
}
```

Что убирает необходимость в написии -> decltype(использование аргументов)

## LLD pattern and paradigms

### CRTP pattern

Паттерн призван убрать вызовы виртуальных методов наследников в runtime и сделать возможным полиморфизм, используя шаблоны, т.е полиморфизм в compile time.

Для того, чтобы реализовать этот паттерн необходимо создать базовый класс и сделать его шаблонным.  В этом классе должен быть метод, который будет кастовать this к указателю на параметр шаблона. 

В каждой функции базового класса мы будем вызывать методы класса наследника, за счет этого, если в классе наследнике не реализован вызываемый метод, то мы получим ошибку на этапе компиляции.

Наследник должен наследоваться от базового шаблонного класса, параметризируя собой же шаблонный параметр базового класса.

Пример реализации находиться в папке examples/crpt_pattern.






## C++

### Volatile

???

### Type inference in templates

Псевдокод
```
template<typename T>
void f(ParamType param); // ParamType содержит ссылки и всякие прочие "украшения", например const
``` 

Существует несколько ситуаций для вывода типа ParamType:
1. ParamType является указателем или ссылкой, но не универсальной ссылкой:
**Ссылочность игнорируется**
```cpp
template<typename Т>
void f (T& param); // param представляет собой ссылку

int x = 27; // x type int
const int cx = x; cx type const int
const int& rx = x; rx type const int&


f(x); // T - int, param type - int& 
f(cx); // T - const int, param type const int&
f(rx); // T - const int, param type const int& // отбросили ссылочность T
```

2. ParamType является универсальной ссылкой

```cpp
template<typename Т>
void f ( T&& param) ; // param является универсальной ссылкой

int x = 27;
const int cx = x;
cosnt int& rx = x;

f(x); // x - lvalue, T - int&, param int&

f(cx); // cx - lvalue, T - const int&, param - const int&

f(rx);  // cx - lvalue, T - const int&, param - const int&

f(27); // 27 - rvalue, T - int, param - int&&

```

3. ParamType не является ни указателем, ни ссылкой


```cpp
 27 - rvalue, T - int, param - int&&
ternplate<typeпarne Т>
void f (T pararn); // param передается по значению 

int x = 27;
const int cx = x;
const int& rx = x;

f(x); // T и param int

f(cx); // T и param int

f(rx); // T и param int 
```
Из-за того, что тут параметр будет совершенно новый переменной, то const отбрасывается, ссылочность также отбрасывается



### Type inference **auto**


