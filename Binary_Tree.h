#pragma once
#include <iostream>
#include "Algorithms.h"
#include "Node_Binary.h"
using namespace std;
template <class T>
class Binary_Tree
{
    Node_Binary<T>* root;
    int n;
    void print_node(Node_Binary<T>*);
    bool find_node(Node_Binary<T>*,T);
    void insertAt(Node_Binary<T>*,T);
    void removeAt(Node_Binary<T>*,Node_Binary<T> *,T);
    void remove_semi_leaf(Node_Binary<T>*);
    void remove_subtree(Node_Binary<T>*);
    Node_Binary<T>* largest_node(Node_Binary<T>*,Node_Binary<T>*);
    Node_Binary<T>* smallest_node(Node_Binary<T>*,Node_Binary<T>*);
    void null_child(Node_Binary<T> *,Node_Binary<T> *);
public:
    Binary_Tree();
    Binary_Tree(T);
    Node_Binary<T>* tree_root();
    void initial();
    bool is_leaf(Node_Binary<T>*);
    bool is_semi_leaf(Node_Binary<T>*);
    void insert(T);
    void remove(T);
    bool find(T);
    void print();
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
    Node_Binary<T>* temp = new Node_Binary<T>(d);
    root = temp;
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
bool Binary_Tree<T>::is_leaf(Node_Binary<T> * node)
{
    return node->left == nullptr && node->right == nullptr;
}

template<class T>
bool Binary_Tree<T>::is_semi_leaf(Node_Binary<T> * node)
{
    return node->left == nullptr || node->right == nullptr;
}

template<class T>
void Binary_Tree<T>::insert(T d)
{
    if(this->empty())
    {
        Node_Binary<T> * new_node = new Node_Binary<T>(d);
        root = new_node;
        n++;
        return;
    }
    insertAt(root,d);
}

template<class T>
void Binary_Tree<T>::remove(T d)
{
    if(this->empty())
        return;
    removeAt(root,nullptr,d);
}

template<class T>
bool Binary_Tree<T>::find(T d)
{
    if(this->empty())
        return false;
    return find_node(root,d);
}

template<class T>
void Binary_Tree<T>::print()
{
    if(this->empty())
        return;
    print_node(root);

    cout << endl;
}

template<class T>
void Binary_Tree<T>::print_node(Node_Binary<T> * node)
{
    if(node == nullptr)
        return;
    cout << node->data << " ";
    print_node(node->left);
    print_node(node->right);
}

template<class T>
bool Binary_Tree<T>::find_node(Node_Binary<T> * node, T d)
{
    if(node == nullptr)
        return false;
    if(d == node->data)
        return true;
    if(d < node->data)
        return find_node(node->left,d);
    if(d > node->data)
        return find_node(node->right,d);
}

template<class T>
void Binary_Tree<T>::insertAt(Node_Binary<T> * node, T d)
{
    if(is_semi_leaf(node))
    {
        if(d == node->data)
            return;
        if(d < node->data && node->left == nullptr)
        {
            Node_Binary<T> * new_node = new Node_Binary<T>(d);
            n++;
            node->left = new_node;
            return;
        }
        if(d > node->data && node->right == nullptr)
        {
            Node_Binary<T> * new_node = new Node_Binary<T>(d);
            n++;
            node->right = new_node;
            return;
        }
    }
    if(d == node->data)
        return;
    if(d < node->data)
        insertAt(node->left,d);
    if(d > node->data)
        insertAt(node->right,d);
}

template<class T>
void Binary_Tree<T>::removeAt(Node_Binary<T> * node,Node_Binary<T> * parent, T d)
{
    if(node == nullptr)
        return;
    if(d == node->data)
    {
        if(this->is_leaf(node))
        {
            null_child(node,parent);
            delete node;
            n--;
            return;
        }
        if(this->is_semi_leaf(node))
        {
            remove_semi_leaf(node);
            return;
        }
        else
        {
            remove_subtree(node);
            return;
        }
    }
    if(d < node->data)
        removeAt(node->left,node,d);
    if(d > node->data)
        removeAt(node->right,node,d);
}

template<class T>
void Binary_Tree<T>::remove_semi_leaf(Node_Binary<T> * node)
{
    if(node->left == nullptr)
    {
        swap(node->right->data,node->data);
        Node_Binary<T> * temp = node->right;
        node->right = nullptr;
        delete temp;
    }
    else if(node->right == nullptr)
    {
        swap(node->left->data,node->data);
        Node_Binary<T> * temp = node->left;
        node->left = nullptr;
        delete temp;
    }
    n--;
}

template<class T>
void Binary_Tree<T>::remove_subtree(Node_Binary<T> * node)
{
    Node_Binary<T> * small_node_parent = smallest_node(node,node->right);
    node->data = small_node_parent->left->data;

    Node_Binary<T> * temp = small_node_parent->left;
    small_node_parent->left = nullptr;
    delete temp;
    n--;
}

template<class T>
Node_Binary<T> *Binary_Tree<T>::largest_node(Node_Binary<T> * parent,Node_Binary<T>* child)
{
    if(child->right == nullptr)
        return parent;
    return largest_node(child,child->right);
}

template<class T>
Node_Binary<T> *Binary_Tree<T>::smallest_node(Node_Binary<T> * parent,Node_Binary<T> * child)
{
    if(child->left == nullptr)
        return parent;
    return smallest_node(child,child->left);
}

template<class T>
void Binary_Tree<T>::null_child(Node_Binary<T> * node,Node_Binary<T> * parent)
{
    if(parent == nullptr)
    {
        root = nullptr;
        return;
    }
    if(parent->data > node->data)
        parent->left = nullptr;
    else if(parent->data < node->data)
        parent->right = nullptr;
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
