#pragma once
template <class T>
class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T data = 0,Node<T>* next = nullptr,Node<T>* prev = nullptr)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
