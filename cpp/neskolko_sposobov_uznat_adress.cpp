#include <iostream>
#include <vector>
#include <array>
#include <stdio.h>
using namespace std;

int main()
{
    vector<vector<uint8_t>> data = {{0x41,0x42},{0x43,0x44}};
    cout << reinterpret_cast<void*> (&data[0][0])  << endl;
    cout << (void*) &data[0][0]  << endl;
    printf("%p\n",&data[0][0]);
    for (auto &i: data)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }

    return 0;
}

