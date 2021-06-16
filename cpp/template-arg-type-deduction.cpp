// Статья об этом здесь https://habr.com/ru/post/206458/
#include <stdio.h>
template<typename T, T... Elements> class Foo0{};
template<auto... VS> class Foo1{ };
template<auto V1, decltype(V1)... VS> class Foo2{ };

int main()
{
    printf("Hello World");
    
    // Foo0<1, 'a', true> vals1;
    Foo0<int, 1, 2, 3> vals2;
    // Foo0<> vals3;
    Foo1<1, 2, 3> vals4; 
    Foo1<1, 'a', true> vals5;
    Foo1<> vals6;
    // Foo2<> vals7;
    Foo2<1, 'a', true> vals8;
    Foo2<1, 2, 3> vals9; 

    return 0;
}
