#include <iostream>
class StringPointer {
public:
    std::string *operator->() {return feed;}
    operator std::string*() {return feed;}
    StringPointer(std::string *Pointer) {Pointer ? feed = Pointer : feed = new std::string();}
private:
    std::string *feed;
};

int main()
{
    std::string s1 = "Hello, world!";

    StringPointer sp1(&s1);
    StringPointer sp2(NULL);

    std::cout << sp1->length() << std::endl;
    std::cout << *sp1 << std::endl;
    std::cout << sp2->length() << std::endl;
    std::cout << *sp2 << std::endl;
}
