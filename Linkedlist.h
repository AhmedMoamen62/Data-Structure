#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Linkedlist
{
    Node<T>* head,* tail;
    int n; //size
    void remove(Node<T>*);
    void insert(Node<T>*,T);
    void swap(T&,T&);
    T& getel(int);
public:
    Linkedlist();
    bool empty();
    int length();
    void push_front(T);
    void pop_front();
    void push_back(T);
    void pop_back();
    void removeAt(int);
    void insertAt(int,T);
    void remove(T);
    int indexOf(T);
    void print(bool inverse = false);
    bool contains(T);
    void clear();
    void bubble_sort();
    T& operator[](int);
    ~Linkedlist();
};

template<typename T>
void Linkedlist<T>::remove(Node<T>* node)
{
    if(node->next == nullptr)
    {
        pop_back();
        return;
    }
    if(node->prev == nullptr)
    {
        pop_front();
        return;
    }
    Node<T> * prev = node->prev;
    Node<T> * next = node->next;
    prev->next = next;
    next->prev = prev;
    delete node;
    n--;
}

template<typename T>
void Linkedlist<T>::insert(Node<T> * node,T d)
{
    if(node->next == nullptr)
    {
        push_back(d);
        return;
    }
    if(node->prev == nullptr)
    {
        push_front(d);
        return;
    }
    Node<T>* new_node = new Node<T>(d,node->next,node);
    node->next = new_node;
    node->next->prev = new_node;
    n++;
}

template<typename T>
void Linkedlist<T>::swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}


template<typename T>
T& Linkedlist<T>::getel(int index)
{
    Node<T>* node_left = this->head;
    Node<T>* node_right = this->tail;
    for(int i = 0 ,j = n - 1; i != index && j != index; i++,j--)
    {
        node_left = node_left->next;
        node_right = node_right->prev;
    }
    if(index < n/2)
    {
        return node_left->data;
    }
    else
    {
        return node_right->data;
    }
}

template<typename T>
Linkedlist<T>::Linkedlist()
{
    n = 0;
    head = nullptr;
    tail = nullptr;
}
template<typename T>
bool Linkedlist<T>::empty()
{
    return this->head == nullptr;
}

template<typename T>
int Linkedlist<T>::length()
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

template<typename T>
void Linkedlist<T>::push_front(T d)
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

template<typename T>
void Linkedlist<T>::pop_front()
{
    if(this->empty())
    {
        return;
    }
    Node<T>* temp = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
    delete temp;
    n--;
}

template<class T>
void Linkedlist<T>::push_back(T d)
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

template<typename T>
void Linkedlist<T>::pop_back()
{
    if(this->empty())
    {
        return;
    }
    Node<T>* temp = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    delete temp;
    n--;
}

template<typename T>
void Linkedlist<T>::removeAt(int index)
{
    if(index < 0 || index > n - 1 || this->empty())
    {
        return;
    }
    Node<T>* node_left = this->head;
    Node<T>* node_right = this->tail;
    for(int i = 0 ,j = n - 1; i != index && j != index; i++,j--)
    {
        node_left = node_left->next;
        node_right = node_right->prev;
    }
    if(index < n/2)
    {
        remove(node_left);
    }
    else
    {
        remove(node_right);
    }
}

template<typename T>
void Linkedlist<T>::insertAt(int index,T d)
{
    if(index < 0 || index > n - 1)
    {
        return;
    }
    Node<T>* node_left = this->head;
    Node<T>* node_right = this->tail;
    for(int i = 0 ,j = n - 1; i != index - 1 && j != index - 1; i++,j--)
    {
        node_left = node_left->next;
        node_right = node_right->prev;
    }
    if(index <= n/2)
    {
        insert(node_left,d);
    }
    else
    {
        insert(node_right,d);
    }
}

template<typename T>
void Linkedlist<T>::remove(T d)
{
    int index = indexOf(d);
    if(index == -1)
        return;
    removeAt(index);
    n--;
}

template<typename T>
int Linkedlist<T>::indexOf(T d)
{
    if(this->empty())
    {
        return -1;
    }
    Node<T>* node_left = this->head;
    Node<T>* node_right = this->tail;
    for(int i = 0 ,j = n - 1; i <= n - 1 && j >= 0; i++,j--)
    {
        if(node_left->data == d)
            return i;
        if(node_right->data == d)
            return j;
        node_left = node_left->next;
        node_right = node_right->prev;
    }
    return -1;
}

template<typename T>
void Linkedlist<T>::print(bool inverse)
{
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

template<typename T>
bool Linkedlist<T>::contains(T d)
{
    return indexOf(d) != -1;
//    if(this->empty())
//    {
//        return false;
//    }
//    Node<T>* trav = this->head;
//    while(trav != nullptr)
//    {
//        if(trav->data == d)
//        {
//            return true;
//        }
//        trav = trav->next;
//    }
//    return false;
}

template<typename T>
void Linkedlist<T>::clear()
{
    while (!this->empty())
    {
        pop_back();
    }
    n = 0;
//    if(this->empty())
//    {
//        return;
//    }
//    Node<T>* trav = this->head;
//    while(trav != nullptr)
//    {
//        Node<T>* temp = trav->next;
//        delete trav;
//        trav = temp;
//    }
//    this->head = nullptr;
//    this->tail = nullptr;
    //    n = 0;
}

template<typename T>
void Linkedlist<T>::bubble_sort()
{
    if(this->empty())
        return;
    for(int i = 0; i < n ; i++)
    {
        bool swapped = false;
        Node<T>* current = head;
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(current->data > current->next->data)
            {
                swap(current->data,current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        if(!swapped)
            return;
    }
}

template<typename T>
T& Linkedlist<T>::operator[](int index)
{
    return getel(index);
}

template<typename T>
Linkedlist<T>::~Linkedlist()
{
    clear();
}
