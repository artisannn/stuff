#include <iostream>
#include <memory>

struct B;

struct A
{
	int val;
	std::shared_ptr<B> b;
	A(){	std::cout<<"A()"<<std::endl; 	};
	~A(){	std::cout<<"~A()"<<std::endl;	};
};

struct B
{
	int val;
	std::shared_ptr<A> a;
	B(){	std::cout<<"B()"<<std::endl; 	};
	~B(){	std::cout<<"~B()"<<std::endl;	};
};

/*
int main ()
{
	std::shared_ptr<A>p1(new A);	// Вызываются кострукторы и деструкторы, все хорошо
	std::shared_ptr<B>p2(new B);
}

int main ()
{
	std::shared_ptr<A>a(new A);	
	std::shared_ptr<B>b(new B);

	// А теперь циклическая ссылка:
	a->b = b;
	b->a = a;	// тут уже деструкторы О. не вызовутся, т.к. оба О. остались ссылаться друг на друга и счетчик ссылок НА РЕСУРС каждого остался = 1 
			// у каждого и ни никто не удалился.
			// можно воспользоваться weak_ptr вместо shared_ptr в О. т.к. weak_ptr НЕ УВЕЛИЧИВАЕТ СЧЕТЧИК ССЫЛОК НА РЕСУРС, более того,
			// weak_ptr не может непосредственно ссылаться на О., он может это делать лишь через sh_ptr, соотв-но, пока живет последний shared_ptr на о., weak_ptr будет возвращать валидный shared_ptr			
			// а еще через него нельзя обращаться туда куда он указывает т.к. у него не определн оператор "->"
			// вместо этого используют функцию lock(), она выдает о. класса shared_ptr если счетчик ссылок != 0, а если 0 то выдает null
			// обобщая, такое произошло из-за того что внутренние sh_ptr'ы лежат не на стеке а в куче, немсотря на то что внешние лежали на стеке и удалились,
			// соотв-но их деструкторы внутренних никто не вызовет кроме самого разраба. Чтобы автоматизировать удаление внутренних, используют w_ptr'ы
			// !!! 
			//
}*/
int main ()
{
	//A * a = new A; 
	//std::weak_ptr<A> wpt(*a); //weak_ptr инициализируется только shared_ptr или weak_ptr!! в отличие от shared_ptr который иниц-ся УКАЗАТЕЛЕМ О. на кот-ый будет ссылается
	
	//auto a = new std::shared_ptr<A> (new A); 	// все лежит в куче, и sh_ptr и O.
	//std::weak_ptr<A> wptr (*a); 			//
							// 
	std::shared_ptr<A>a(new A);	
	std::shared_ptr<B>b(new B);
	a->b = b;			// инициализируем weak_ptr
	b->a = a;

	//std::weak_ptr<int> wptr(new int(2000));		
	return 0;
}