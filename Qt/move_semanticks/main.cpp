#include <iostream>

using namespace std;

struct A
{
    A(const char *s = nullptr)
        :s_(s ? s : "")
    {   cout<<"A()"<<endl;
        cout<<"this : "<< this<<endl;
                cout<<"A::s_ adress: "<< s_.data()<<endl;
        }
        A(const A &other)
                :s_(other.s_)
    {   cout<<"A(A& a)"<<endl;
        cout<<"this : "<< this<<endl;
                cout<<"A::s_ adress: "<< s_.data()<<endl;
        }

        A(const A &&other)
        :s_(move(other.s_))
    {   cout<<"A( A&& other)"<<endl;
        cout<<"this : "<< this<<endl;
                cout<<"A::s_ adress: "<< s_.data()<<endl;
        }

        A &operator=(const A& other)
    {

    }

    ~A()
    {   cout<<"~A()"<<endl;
                cout<<"this : "<< this<<endl;   }

    std::string s_;
};

A f(A a)
{
    return a;
}


int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
