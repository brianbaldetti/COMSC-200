//
//  main.cpp
//  quiz31
//
//  Created by brian on 11/7/22.
//
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

template<class T1, class T2>
class myMap
{
private:
    vector<pair<T1, T2>> privateVector;
public:
    typename vector<pair<T1, T2>>::iterator insert(pair<T1, T2> in)
    {
        privateVector.push_back(in);
        auto it = privateVector.end();
        return --it;
    }
    void display() const
    {
        for (auto it : privateVector)
            cout << it.first << " " << it.second << endl;
    }
};

int main()
{
    myMap<char, int> mp1;

    mp1.insert(pair<char, int>('c', 300));
    mp1.insert(pair<char, int>('b', 200));
    mp1.insert(pair<char, int>('s', 904));
    mp1.insert(pair<char, int>('a', 100));
    mp1.insert(pair<char, int>('z', 900));
    mp1.insert(pair<char, int>('t', 203));

    mp1.display();
    
    return 0;
}
