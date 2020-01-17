#include <iostream>
#include <memory>
#include <thread>
#include <chrono>


// Эта структура специально сделана чтоб заменить обычный int чтобы увидеть
// вызывается ли деструктор у инта при удалении объекта типа A через deleter
// передаваемый в шаред пойнтер в виде лямбды(внутри ф-ии func())
struct MyInt{
    MyInt(int in = 1):i(in){ std::cout << "MyInt: " << i << std::endl; }
    ~MyInt(){ std::cout << "~MyInt: " << i << std::endl; }
    int i;
};


// Структура А описывает тот класс структур которые не RAII т.е.
// они ни хрена не подчищают за собой память
struct A 
{
    void printme() { 
        for (int i=0; i<5 ; i++)
           { std::cout << arr[i].i << ""; }
        std::cout<< std::endl;
    }
    A(int in = 0) {
        arr = new MyInt[5];
        for(int i=0 ; i<5 ; i++ ) { arr[i].i=in; }
        printme();
    }
    ~A() {
        std::cout << "~A()" << std::endl;
    }
    MyInt * arr;
};

// А структура В это почти RAII, в своем деструкторе удаляет захваченную память,
// почти потомучто в конструкторе может вылететь исключение (напр в printme())
// и все, объект считай не создался, значит деструктор никто не вызовит, 
// а память под массив уже выделена и гуляет где-то там в зомбиленде.
// Пока память. Чтоб избежать таких вещей нужно пользоваться RAII структкрами
// т.е. поля делать std::string, std::vector вместо всяких char*

struct B 
{
    void printme() { 
        for (int i=0; i<5 ; i++)
           { std::cout << arr[i] << ""; }
        std::cout<< std::endl;
    }
    B() {
        arr = new int[5];
        printme();
    }
    ~B() {
        std::cout<< "~B()" << std::endl;
        delete[] arr;
    }    
    int * arr;
};

void func ()
{
    // Для типа А тоже есть RAII подход:
    // при создании умного указателя на него просто передаем лямбду
    // в которой прописываем все дейтсвия для очистки памяти:
        A a;
        auto deleter = [](A *a){delete a->arr;};
        std::shared_ptr<A> d(&a,deleter);
    // Так же есть вариант работы с объектом А лежащим в куче:
        auto deleter2 = [](A *a){delete a->arr; delete a;};
    // Что если у класса А поле а в приватой секции? Будет ли оно доступно в теле лямбды (delete a->arr)?
        std::shared_ptr<A> d2(new A,deleter2);

    // Посмотрим, что происходит когда шаред_птр перестает ссылаться на одного
    // и начинает ссылаться на другого
        std::shared_ptr<B> b1 = std::make_shared<B>();
        std::shared_ptr<B> b2 = std::make_shared<B>();
        b1=b2;
        std::this_thread::sleep_for(std::chrono::seconds(3));

}
void func2()
{
// первый вариант без делитера, значит деструктор А вызовется
// но ее внутренний массив не удалиться т.к. А не RAII
// в консоль должно высветиться только "~A()"
    auto t1 = std::make_shared<A>(7);

// второй вариант с делитером, ожидаем что вызовется и
// "~A()" и "MyInt: 8"
    auto deleter = [](A *a){delete a->arr;};
    auto t2 = std::shared_ptr<A>(new A(8),deleter);
    t2->printme();
}

int main(int c, char** v)
{
// специально все происходит в отдельной функции чтоб имитировать выход из скоупа
//    func();
    func2();

}
