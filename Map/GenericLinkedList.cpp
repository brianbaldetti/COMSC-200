//
//  main.cpp
//  hw07
//
//  Created by brian on 11/13/22.
//
#include <iostream>
using namespace std;

template<class T>
class Deque {
    struct listNode {
        T data;
        int index = 0;  /// the index for the element
        listNode* next = nullptr;
        listNode* previous = nullptr;
    };
    listNode* head = nullptr;
    listNode* tail = nullptr;

public:
    ~Deque() {
        /// ADD YOUR CODE HERE
        /// Release all dynamically allocated memory
        listNode * tmp = nullptr;
        for (listNode * i = head; i != nullptr;)
        {
            tmp = i;
            i = i->next;
            delete tmp;
        }
    }

    void push_back(T value) {
        /// ADD YOUR CODE HERE
        /// Add the element of the value to the end of the list
        
        //runs if obj is empty
        if (!head)
        {
            listNode * newNode = new listNode;
            newNode->data = value;
            newNode->index = 0;
            head = newNode;
            tail = newNode;
        }
        else
        {
            listNode * newNode = new listNode;
            newNode->data = value;
            newNode->previous = tail;
            newNode->index = (tail->index + 1);
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(T value) {
        /// ADD YOUR CODE HERE
        /// Add the element of the value to the beginning of the list
        
        //runs if obj is empty
        if (!head)
        {
            listNode * newNode = new listNode;
            newNode->data = value;
            newNode->next = head;
            newNode->index = 0;
            head = newNode;
            tail = newNode;
        }
        else
        {
            listNode * newNode = new listNode;
            newNode->data = value;
            newNode->next = head;
            newNode->index = 0;
            head->previous = newNode;
            head = newNode;
        }
        
        //increment the index of all nodes
        for (listNode * i = head->next; i != nullptr; i = i->next)
        {
            i->index++;
        }
    }

    void display_forward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from head to tail
        /// Use the link next to move the next node. (Do NOT use index.)
        for (listNode * i = head; i != nullptr; i = i->next)
        {
            cout << i->index << " " << i->data << endl;
        }
        
    }

    void display_backward() {
        /// ADD YOUR CODE HERE
        /// Display the values in the list from tail to head
        /// Use the link precious to move the previous node. (Do NOT use index.)
        for (listNode * i = tail; i != nullptr; i = i->previous)
        {
            cout << i->index << " " << i->data << endl;
        }
    }

    T operator[] (int index) {
        /// ADD YOUR CODE HERE
        /// With the index, the value of the element is displayed
        listNode * tmp = head;
        int i = 0;
        while (i < index)
        {
            tmp = tmp->next;
            i++;
        }
        
        return tmp->data;
    }

    int size()
    {
         /// ADD YOUR CODE HERE
         /// Return the size of the list
        return (tail->index + 1);
    }
};

int main() {
    Deque<int> deque1;
    
    deque1.push_back(11);
    deque1.push_back(22);
    deque1.push_back(33);
    
    cout << "Checking push_back()" << endl;
    deque1.display_forward();  /// Should display   11  22  33
    cin.ignore();
    deque1.display_backward();  /// Should display   33  22  11
    
    deque1.push_front(0);
    cout << endl << endl << "Checking push_front()" << endl;
    deque1.display_forward();  /// Should display   0  11  22  33
    cin.ignore();
    deque1.display_backward();  /// Should display   33  22  11  0
    
    cout << endl << endl << "Checking operator []" << endl;
    for (int i = 0; i < deque1.size(); i++)
    {
        cout << deque1[i] << endl;
    }

    return 0;
}
