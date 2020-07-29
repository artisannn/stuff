#include <iostream>
using namespace std;
/* 
	?:  .  sizeof ::  .*  -can't be overloaded!
	=, [], (), ->, (type)  - only as class members (methods)

	-, +, --, ++  - other unary operators and mutators usually as methods
	other binary operators are usually as global friend functions

	return value
	=, prefix ++ and -- returns only reference!
	<, =, >, <=, ==, >=, != - returns bool
	others return copy of this* or one of operands
*/
struct B {};

struct A {
	A operator+(B b) {	cout << "A::+" << endl; return A();	};
	A operator-(B b) {	cout << "A::-" << endl; return A();	};
};


int main(){
	A a;
	B b;
	a + b;
	return 0;
};
