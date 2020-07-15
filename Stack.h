#pragma once
#include <iostream>
#include "Algorithms.h"
#include "Node.h"
using namespace std;

template <class T>
class Stack
{
    Node<T>* head,* tail;
    int n; //size
public:
    Stack();
    Stack(T);
    bool empty();
    int length();
    void push(T);
    void pop();
    T peek();
    void print(bool inverse = false);
    void clear();
    ~Stack();
};

template<class T>
Stack<T>::Stack()
{
    n = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
Stack<T>::Stack(T d)
{
    n = 1;
    push(d);
}

template<class T>
bool Stack<T>::empty()
{
    return this->head == nullptr;
}

template<class T>
int Stack<T>::length()
{
    Node<T> * trav = this->head;
    int length = 0;
    while(trav != nullptr)
    {
        length++;
        trav = trav->next;
    }
    return length;
}

template<class T>
void Stack<T>::push(T d)
{
    Node<T>* new_head = new Node<T>(d,this->head);
    if(this->empty())
    {
        this->head = new_head;
        this->tail = new_head;
        n++;
        return;
    }
    this->head->prev = new_head;
    this->head = new_head;
    n++;
}

template<class T>
void Stack<T>::pop()
{
    if(this->empty())
    {
        return;
    }
    Node<T>* temp = this->head;
    this->head = this->head->next;
    if(this->tail != nullptr)
        this->tail->next = nullptr;
    else
        this->head = nullptr;
    delete temp;
    n--;
}

template<class T>
T Stack<T>::peek()
{
    if(!this->empty())
    {
        return this->head->data;
    }
}

template<class T>
void Stack<T>::print(bool inverse)
{
    if(this->empty())
        return;
    if(!inverse)
    {
        Node<T>* trav = this->head;
        while (trav != nullptr)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
    }
    else
    {
        Node<T>* trav = this->tail;
        while (trav != nullptr)
        {
            cout << trav->data << " ";
            trav = trav->prev;
        }
    }
    cout << endl;
}

template<class T>
void Stack<T>::clear()
{
    if(this->empty())
        return;
    pop();
    clear();
}

template<class T>
Stack<T>::~Stack()
{
    clear();
}
