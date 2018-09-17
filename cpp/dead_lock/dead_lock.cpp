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
	std::shared_ptr<A>p1(new A);	// ���������� ����������� � �����������, ��� ������
	std::shared_ptr<B>p2(new B);
}

int main ()
{
	std::shared_ptr<A>a(new A);	
	std::shared_ptr<B>b(new B);

	// � ������ ����������� ������:
	a->b = b;
	b->a = a;	// ��� ��� ����������� �. �� ���������, �.�. ��� �. �������� ��������� ���� �� ����� � ������� ������ �� ������ ������� ������� = 1 
			// � ������� � �� ����� �� ��������.
			// ����� ��������������� weak_ptr ������ shared_ptr � �. �.�. weak_ptr �� ����������� ������� ������ �� ������, ����� ����,
			// weak_ptr �� ����� ��������������� ��������� �� �., �� ����� ��� ������ ���� ����� sh_ptr, �����-��, ���� ����� ��������� shared_ptr �� �., weak_ptr ����� ���������� �������� shared_ptr			
			// � ��� ����� ���� ������ ���������� ���� ���� �� ��������� �.�. � ���� �� �������� �������� "->"
			// ������ ����� ���������� ������� lock(), ��� ������ �. ������ shared_ptr ���� ������� ������ != 0, � ���� 0 �� ������ null
			// �������, ����� ��������� ��-�� ���� ��� ���������� sh_ptr'� ����� �� �� ����� � � ����, �������� �� �� ��� ������� ������ �� ����� � ���������,
			// �����-�� �� ����������� ���������� ����� �� ������� ����� ������ �������. ����� ���������������� �������� ����������, ���������� w_ptr'�
			// !!! 
			//
}*/
int main ()
{
	//A * a = new A; 
	//std::weak_ptr<A> wpt(*a); //weak_ptr ���������������� ������ shared_ptr ��� weak_ptr!! � ������� �� shared_ptr ������� ����-�� ���������� �. �� ���-�� ����� ���������
	
	//auto a = new std::shared_ptr<A> (new A); 	// ��� ����� � ����, � sh_ptr � O.
	//std::weak_ptr<A> wptr (*a); 			//
							// 
	std::shared_ptr<A>a(new A);	
	std::shared_ptr<B>b(new B);
	a->b = b;			// �������������� weak_ptr
	b->a = a;

	//std::weak_ptr<int> wptr(new int(2000));		
	return 0;
}