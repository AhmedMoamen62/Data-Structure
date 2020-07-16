#pragma once
#include <iostream>
#include "Node_Binary.h"
#include "Algorithms.h"
using namespace std;
template <class T>
class Binary_Tree
{
    Node_Binary<T>* root;
    int n;
public:
    Binary_Tree();
    Binary_Tree(T);
    Node_Binary<T>* tree_root();
    void initial();
    bool empty();
    ~Binary_Tree();
};


template<class T>
Binary_Tree<T>::Binary_Tree()
{
    n = 0;
    root = nullptr;
}

template<class T>
Binary_Tree<T>::Binary_Tree(T d)
{
    n = 1;
    root->data = d;
}

template<class T>
Node_Binary<T> *Binary_Tree<T>::tree_root()
{
    return this->root;
}

template<class T>
void Binary_Tree<T>::initial()
{
    Node_Binary<T>* temp1 = new Node_Binary<T>("+");
    this->root = temp1;

    Node_Binary<T>* temp2 = new Node_Binary<T>("2");
    this->root->left = temp2;

    Node_Binary<T>* temp3 = new Node_Binary<T>("*");
    this->root->right = temp3;

    Node_Binary<T>* temp4 = new Node_Binary<T>("3");
    this->root->right->left = temp4;

    Node_Binary<T>* temp5 = new Node_Binary<T>("5");
    this->root->right->right = temp5;
}

template<class T>
bool Binary_Tree<T>::empty()
{
    return this->root == nullptr;
}

template<class T>
Binary_Tree<T>::~Binary_Tree()
{

}
