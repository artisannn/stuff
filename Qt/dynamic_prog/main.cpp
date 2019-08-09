#include <iostream>
#include <vector>
using namespace std;

vector<int> fibb (int n)
{
    vector<int> res(n, 0);
    res[0] = 1;
    res[1] = 1;
    for (auto i = res.begin()+2; i < res.end(); i++)
    {
        *i = *(i-1) + *(i-2);
    }
    return res;
}

vector <int> coin_stairs (vector <int> prices)
{
    vector<int> res(prices.size()+1, 0);
    res[0] = 0;
    res[1] = prices[0];
    for (auto i = res.begin()+2 ; i < res.end(); i++)
    {
        int res_index = distance(res.begin(), i) - 1;
        *i = prices[res_index] + max(*(i-1), *(i-2));
    }
    return res;
}

vector <int> grasshopper(vector<char> path)
{
    vector <int> res (path.size(), -1);
    res[0] = 0;
    for (auto i = res.begin()+1; i<res.end(); i++)
    {
        int res_index = distance(res.begin(), i);
        if (path[res_index] != 'w')
        {
            if (res_index >= 5)
            {

            }
            else if (res_index >= 3)
            {

            }
            else
            {
                *i = *(i-1) + path[res_index];
            }
        }
    }
}

int main()
{
//    for (auto i:coin_stairs({3,1,-4,1,5,9,-2,-6}))
//        cout << i << ' ';
//    cout << endl;
    for (auto i:coin_stairs({3,1,-4,1,5,9,-2,-6}))
        cout << i << ' ';
    cout << endl;

    return 0;
}

