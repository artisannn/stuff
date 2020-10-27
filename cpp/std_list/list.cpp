#include <iostream>
#include <list>
#include <vector>
#include "art_tools.h"

using namespace std;
   
int main (){
    list<int> l = {1,2,3,4,5,6,7,8,9,10};
    cout << l;
    for (auto& i : l){
        cout << i;
        if(i = 5){
            auto first = l.begin();
            std::advance(first, 6);
            l.splice(l.begin(), l, l.end());
        }
    }
    cout << l;
}