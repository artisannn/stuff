#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

// Структура А описывает тот класс структур которые не RAII т.е.
// они ни хрена не подчищают за собой память
struct A 
{
    int * arr;
    void printme() { 
        for (int i=0; i<10 ; i++)
           { std::cout << arr[i] << std::endl; }
    }
    A() {
        arr = new int[10];
        printme();
    }
    ~A() { }    
};

// А структура В это почти RAII, в своем деструкторе удаляет захваченную память,
// почти потомучто в конструкторе может вылететь исключение (напр в printme())
// и все, объект считай не создался, значит деструктор никто не вызовит, 
// а память под массив уже выделена и гуляет где-то там в зомбиленде,
// пока память. Чтоб избежать таких вещей нужно пользоваться RAII структкрами
// т.е. поля делать std::string, std::vector вместо всяких char*
struct B 
{
    int * arr;
    void printme() { 
        for (int i=0; i<10 ; i++)
           { std::cout << arr[i] << std::endl; }
    }
    B() {
        arr = new int[10];
        printme();
    }
    ~B() {
        std::cout<< "~B()" << std::endl;
        delete[] arr;
    }    
};



int main(int c, char** v)
{
// Для типа А тоже есть RAII подход:
// при сохдании умного указателя на него просто передаем лямбду
// в которой прописываем все дейтсвия для очистки памяти:
    A a;
    auto deleter = [](A *a){delete a->arr;};
    std::shared_ptr<A> d(&a,deleter);
// Так же есть вариант работы с объектом А лежащим в куче:
    auto deleter2 = [](A *a){delete a->arr; delete a;};
    std::shared_ptr<A> d2(new A,deleter2);
    
// Посмотрим, что происходит когда шаред_птр перестает ссылаться на одного 
// и начинает ссылаться на другого
    std::shared_ptr<B> b1 = std::make_shared<B>();
    std::shared_ptr<B> b2 = std::make_shared<B>();
    b1=b2;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    
    
}
