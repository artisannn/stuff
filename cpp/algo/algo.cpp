#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
#include <typeinfo>

int main ()
{
    auto mp = std::map<int,std::string>{{1,"one"},{2,"two"},{3,"three"},{4,"four"},{5,"five"},{6,"six"},{7,"seven"}};

    auto v1 = std::vector<int>{1,7,3,8,9,4,8,90,4,78,4,3};
    std::string s("Мама мыла раму");

    auto v2 = std::vector<int>{1,7,3,8,9,4,8,90,4,79,4,3};
    auto p = std::mismatch(v1.begin(),v1.end(),v2.begin(),v2.end());
    std::cout<<"first: " << *p.first << ", second: " << *p.second << std::endl;
    
    std::string s1("рам");
    std::search(s1.begin(),s1.end(),s.begin(),s.end());
}

