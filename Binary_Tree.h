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
    void deleteNode(Node_Binary<T>*);
    void preorder(Node_Binary<T>*);
    void inorder(Node_Binary<T>*);
    void postorder(Node_Binary<T>*);
    bool find_node(Node_Binary<T>*,T);
    void insertAt(Node_Binary<T>*,T);
    void removeAt(Node_Binary<T>*,Node_Binary<T> *,T);
    void remove_semi_leaf(Node_Binary<T>*);
    void remove_subtree(Node_Binary<T>*);
    Node_Binary<T>* largest_node(Node_Binary<T>*,Node_Binary<T>*);
    Node_Binary<T>* smallest_node(Node_Binary<T>*,Node_Binary<T>*);
    void null_child(Node_Binary<T> *,Node_Binary<T> *);
    int count_leaves(Node_Binary<T>*);
    int height_of_tree(Node_Binary<T>*);
    int tree_max(Node_Binary<T>*);
    int tree_min(Node_Binary<T>*);
    int evaluate(Node_Binary<T>*);
    int eval(int,int,string);
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
    void print_preorder();
    void print_inorder();
    void print_postorder();
    int number_of_leaves();
    int height();
    int Max();
    int Min();
    int equation_calculator();
    bool empty();
    void clear();
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
void Binary_Tree<T>::print_preorder()
{
    if(this->empty())
        return;
    preorder(root);

    cout << endl;
}

template<class T>
void Binary_Tree<T>::print_inorder()
{
    if(this->empty())
        return;
    inorder(root);

    cout << endl;
}

template<class T>
void Binary_Tree<T>::print_postorder()
{
    if(this->empty())
        return;
    postorder(root);

    cout << endl;
}

template<class T>
int Binary_Tree<T>::number_of_leaves()
{
    return count_leaves(root);
}

template<class T>
int Binary_Tree<T>::height()
{
    return height_of_tree(root);
}

template<class T>
int Binary_Tree<T>::Max()
{
    return tree_max(root);
}

template<class T>
int Binary_Tree<T>::Min()
{
    return tree_min(root);
}

template<class T>
int Binary_Tree<T>::equation_calculator()
{
    return evaluate(root);
}

template<class T>
void Binary_Tree<T>::deleteNode(Node_Binary<T> * node)
{
    if(node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);

    n--;
    delete node;
}

template<class T>
void Binary_Tree<T>::preorder(Node_Binary<T> * node)
{
    if(node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template<class T>
void Binary_Tree<T>::inorder(Node_Binary<T> * node)
{
    if(node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

template<class T>
void Binary_Tree<T>::postorder(Node_Binary<T> * node)
{
    if(node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
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
        swapel(node->right->data,node->data);
        Node_Binary<T> * temp = node->right;
        node->right = nullptr;
        delete temp;
    }
    else if(node->right == nullptr)
    {
        swapel(node->left->data,node->data);
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
int Binary_Tree<T>::count_leaves(Node_Binary<T> * node)
{
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;

    return count_leaves(node->left) + count_leaves(node->right);
}

template<class T>
int Binary_Tree<T>::height_of_tree(Node_Binary<T> * node)
{
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;

    int height_left = height_of_tree(node->left);
    int height_right = height_of_tree(node->right);

    return max(height_left,height_right) + 1;
}

template<class T>
int Binary_Tree<T>::tree_max(Node_Binary<T> * node)
{
    if(node->right == nullptr)
        return node->data;
    return tree_max(node->right);
}

template<class T>
int Binary_Tree<T>::tree_min(Node_Binary<T> * node)
{
    if(node->left == nullptr)
        return node->data;
    return tree_min(node->left);
}

template<class T>
int Binary_Tree<T>::evaluate(Node_Binary<T> * node)
{
    if(node->is_numeric())
        return node->to_numeric();

    int left_subtree = evaluate(node->left);
    int right_subtree = evaluate(node->right);

    return eval(left_subtree,right_subtree,node->data);
}

template<class T>
int Binary_Tree<T>::eval(int left_operand, int right_operand, string op)
{
    if(op == "+")
        return left_operand + right_operand;
    if(op == "-")
        return left_operand - right_operand;
    if(op == "*")
        return left_operand * right_operand;
    if(op == "/")
        return left_operand / right_operand;
    if(op == "^")
        return power(left_operand,right_operand);
}

template<class T>
bool Binary_Tree<T>::empty()
{
    return this->root == nullptr;
}

template<class T>
void Binary_Tree<T>::clear()
{
    if(this->empty())
        return;

    deleteNode(root);
    root = nullptr;
}

template<class T>
Binary_Tree<T>::~Binary_Tree()
{
    clear();
}
