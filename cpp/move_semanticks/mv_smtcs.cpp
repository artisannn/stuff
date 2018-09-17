#include <iostream>
using namespace std;

struct A
{
	A(const char *s = nullptr)
		:s_(s ? s : "")
	{	cout<<"A()"<<endl;
		cout<<"this : "<< this<<endl;	
		cout<<"A::s_ adress: "<< s_.data()<<endl;	};
	A(A &a)
		:s_(a.s_)
	{	cout<<"A(A& a)"<<endl;
		cout<<"this : "<< this<<endl;	
		cout<<"A::s_ adress: "<< s_.data()<<endl;	};

	A( A&& other)
		:s_(move(other.s_))
	{	cout<<"A( A&& other)"<<endl;		
		cout<<"this : "<< this<<endl;	
		cout<<"A::s_ adress: "<< s_.data()<<endl;	};

	A&operator=(const A& other)
	{
		
	}

	~A()
	{	cout<<"~A()"<<endl;		
		cout<<"this : "<< this<<endl;	};

	std::string s_;
};

A f(A a)
{
	return a;
}

int main (int argc, char* argv[])
{
	A a;

	std::cout<< "sizeof(a)" << sizeof(f(a))<< std::endl; // lets look memory aligning ;)
}
