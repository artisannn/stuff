#include <map>
#include <vector>
#include <iostream>

int sockMerchant(int n, std::vector<int> ar) {
    std::map<int,int> sock_pairs;
    for (int i = 0; i < n ; ++i)
    {
        int t = sock_pairs[ar.at(i)];
        sock_pairs[ar.at(i)] = t+1;
    }
    int pair_count;
    for (auto &i : sock_pairs)
    {
        pair_count += i.second / 2;
        std::cout << i.first << ":" << i.second << std::endl;
    }
    return pair_count;
}


int main()
{
    std::map<int,int> _map;
    for (int i = 0; i < 6; i++)

    {
        _map[i];
        std::cout << _map.find(i)->first << ":" << _map.find(i)->second << std::endl;
    }
    sockMerchant(10, {1, 1, 3, 1, 2, 1, 3, 3, 3, 3} );
    std::string s("abcde");
    for (auto i=s.begin(); i != s.end(); ++i )
    {
        std::cout<< "i: " << *i << ", i--: " << *(i-1) << ", i++: "<<*(i+1) <<std::endl;
        if (!*(i+1))
            std::cout << "There is null!" << std::endl;

    }

}

