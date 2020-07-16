#pragma once
#include <iostream>
#include "Algorithms.h"
#include "Node.h"
using namespace std;

template <class T>
class Queue
{
    Node<T>* head,* tail;
    int n; //size
public:
    Queue();
    Queue(T);
    bool empty();
    int length();
    void push(T);
    void pop();
    T front();
    T back();
    void job_statistics();
    void print(bool inverse = false);
    void clear();
    ~Queue();
};

template<class T>
Queue<T>::Queue()
{
    n = 0;
    head = nullptr;
    tail = nullptr;
}

template<class T>
Queue<T>::Queue(T d)
{
    n = 1;
    push(d);
}

template<class T>
bool Queue<T>::empty()
{
    return this->head == nullptr;
}

template<class T>
int Queue<T>::length()
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
void Queue<T>::push(T d)
{
    Node<T>* new_tail = new Node<T>(d,nullptr,this->tail);
    if(this->empty())
    {
        this->head = new_tail;
        this->tail = new_tail;
        n++;
        return;
    }
    this->tail->next = new_tail;
    this->tail = new_tail;
    n++;
}

template<class T>
void Queue<T>::pop()
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
T Queue<T>::back()
{
    if(!this->empty())
    {
        return this->tail->data;
    }
}

template<class T>
void Queue<T>::job_statistics()
{
    int size = this->length();

    T total_service_time = 0;
    T total_waiting_time = 0;
    for(int i = 0; i < size ; i++)
    {
        T current_time = this->front();

        this->pop();

        total_waiting_time += total_service_time;
        total_service_time += current_time;

        this->push(current_time);
    }

    cout << "Total serive time is : " << total_service_time << endl;
    cout << "Total waiting time is : " << (float)total_waiting_time/size << endl;
}

template<class T>
T Queue<T>::front()
{
    if(!this->empty())
    {
        return this->head->data;
    }
}

template<class T>
void Queue<T>::print(bool inverse)
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
void Queue<T>::clear()
{
    if(this->empty())
        return;
    pop();
    clear();
}

template<class T>
Queue<T>::~Queue()
{
    clear();
}
