# one_man_knowledgebase

## Computer science


## LLD pattern and paradigms

### CRTP pattern




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


