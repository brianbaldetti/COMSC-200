//
//  main.cpp
//  q12
//
//  Created by brian on 9/19/22.
//
#include <iostream>
using namespace std;

struct ListNode
{
    int data;
    ListNode *link = nullptr;
};

void appendNode(ListNode *&, int);
void display(ListNode *);
void reverseList(ListNode *&);
void deleteList(ListNode *&);

int main()
{
    ListNode *head = nullptr;
    
    cout << "Display  996 -> 997 ->998 -> 999 -> nullptr" << endl;
    appendNode(head, 999);
    appendNode(head, 998);
    appendNode(head, 997);
    appendNode(head, 996);
    reverseList(head);
    display(head);
    deleteList(head);
    
    appendNode(head, 222);
    reverseList(head);
    cout << "Display  222 -> nullptr" << endl;
    display(head);

    appendNode(head, 333);
    reverseList(head);
    cout << "Display  333 -> 222 -> nullptr" << endl;
    display(head);

    appendNode(head, 111);
    reverseList(head);
    cout << "Display  111 -> 222 -> 333 -> nullptr" << endl;
    display(head);

    deleteList(head);
    
    cout << "Display nullptr" << endl;
    display(head);

    return 0;
}

void appendNode(ListNode *&head, int data)
{
    ListNode * newNode = new ListNode;
    newNode->data = data;
    newNode->link = nullptr;

    /// There are two cases here
    if (head == nullptr) /// 1st case, the linked list is empty
    {
        head = newNode;
    }
    else                          /// 2nd case.
    /// The linked list is not empty and the new node should be appended to the end.
    {
        ListNode * p = head;
        
        while (p->link != nullptr) /// Move the pointer to the last node
        {
            p = p->link; /// Move one step at a time
        }
        p->link = newNode; /// p points to the last node now. Connect the new node to it.
    }
}

void display(ListNode *head)
{
    ListNode *p = head;
    if (head != nullptr) /// Do display only when head is not NULL,
        while (p != nullptr)
        {
           cout << p->data << "    ->  ";
           p = p->link;
        }

    cout << "nullptr" << endl << endl;
}

void reverseList(ListNode *& head)
{
    //variables for reversing list
    ListNode* p = nullptr;
    ListNode* q = head;
    ListNode* r = nullptr;
    
    if (head == NULL)
        return;
    else if (head->link == NULL)
        return;
    else if (head->link->link == NULL)
    {
        head->link->link = head;
        head = head->link;
        head->link->link = nullptr;
    }
    else
    {
        while (q != NULL)
        {
            r = q->link;
            q->link = p;
            p = q;
            q = r;
        }
        
        head = p;
    }
}

void deleteList(ListNode *& head)
{
    if (head == NULL)
    {
        return;
    }
    
    ListNode* curr = head;
    ListNode* next = nullptr;
    
    while (curr != NULL)
    {
        next = curr->link;
        delete curr;
        curr = next;
    }
    
    head = nullptr;
}
