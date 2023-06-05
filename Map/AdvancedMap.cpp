//
//  main.cpp
//  quiz31part2
//
//  Created by brian on 11/7/22.
//
#include <iostream>
using namespace std;

template<class T1, class T2>
class myMap
{
private:
    struct node
    {
        T1 first;
        T2 second;
        node * next = nullptr;

    };
    
    node * head = nullptr;
public:
    void insert(T1 fst, T2 snd)
    {
        node * newNode = new node;
        newNode->first = fst;
        newNode->second = snd;
        
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            node * nodePtr = head;
            while (nodePtr->next != nullptr)
            {
                nodePtr = nodePtr->next;
            }
            
            nodePtr->next = newNode;
        }
    }
    void display()
    {
        node * nodePtr = head;
        while (nodePtr != nullptr)
        {
            cout << nodePtr->first << " " << nodePtr->second << endl;
            nodePtr = nodePtr->next;
        }
    }
};

int main()
{
    myMap <char, int> mp1;
    
    mp1.insert('c', 300);
    mp1.insert('b', 200);
    mp1.insert('s', 904);
    mp1.insert('a', 100);
    mp1.insert('z', 900);
    mp1.insert('t', 203);
    mp1.display();
    
    return 0;
}
