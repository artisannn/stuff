#include <iostream>
#include <vector>
using namespace std;


void print_vec(auto vec)
{
    for (auto i : vec)
    {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

vector<int> merge(vector<int> & v1, vector<int> & v2)
{
    vector<int> res(v1.size() + v2.size());
    auto r = res.begin();
    auto i1 = v1.begin();
    auto i2 = v2.begin();
    while(i1 < v1.end() and i2 < v2.end())
    {
        if (*i1 <= *i2)
        {
            *r = *i1;
            i1++;
            r++;
        }
        else
        {
            *r = *i2;
            i2++;
            r++;
        }
    }
    cout << res.size() << endl;

    r = res.insert(r, i1, v1.end());
    res.insert(r, i2, v2.end());

    for (;i2 < v2.end(); i2++)
    {
        cout << *i2 << endl;
    }
    cout << res.size() << endl;
    return res;
}

int main()
{

    vector<int> v = {1,2,3,5};
    vector<int> v2 = {2,4,5,6};
//    cout << "Hello World!" << endl;

//    print_vec(v);
//    cout<< v.capacity() << endl;
//    cout<< v.size() << endl;

//    v.reserve(4);
//    cout<< v.size() << endl;
//    cout<< v.capacity() << endl;

//    v.insert(v.begin()+1, v2.begin(), v2.end());

//    print_vec(v);
//    cout<< v.size() << endl;
    print_vec(v);
    print_vec(v2);

    print_vec(merge(v, v2));


    return 0;
}

