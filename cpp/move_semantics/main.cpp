#include <iostream>

using namespace std;

class A
{
public:
    A(const char * str = nullptr)
    : s(str ? str : "") { cout << "A (char *)" << endl; }
    A(const A& other)
    : s(other.s) {
        cout << "" << endl;
    }
    A(A&& other)
    : s(other.s){
        other.s = nullptr;
    }
    ~A() {}

private:
    string s;
};

int main(void)
{
    printf("Hello World!\n");
    A a;
    return 0;
}
