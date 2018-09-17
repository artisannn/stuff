#include <iostream>
class A
{
	public:
	virtual void who_am_i () {	std::cout<<"I am A type"<<std::endl;	}
};

class B: public A
{
	public:
	void who_am_i () {	std::cout<<"I am B type"<<std::endl;	}
};

int main ()
{
	//A* b = new B();
	B b;
	A a = B();
	a.who_am_i();
	std::cout<<"**********************************************************************************"<< std::endl;
	std::cout<<" Hello, this is test function"<< std::endl;
	std::cout<<"**********************************************************************************" << std::endl;	
	return 0;
}