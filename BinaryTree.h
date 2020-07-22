#pragma once
#include <iostream>
#include "Algorithms.h"
#include "NodeBinary.h"
using namespace std;
template <class T>
class BinaryTree
{
    NodeBinary<T>* root;
    int n;
    void deleteNode(NodeBinary<T>*);
    void preorder(NodeBinary<T>*);
    void inorder(NodeBinary<T>*);
    void postorder(NodeBinary<T>*);
    bool find_node(NodeBinary<T>*,T);
    void insertAt(NodeBinary<T>*,T);
    void removeAt(NodeBinary<T>*,NodeBinary<T> *,T);
    void remove_semi_leaf(NodeBinary<T>*);
    void remove_subtree(NodeBinary<T>*);
    NodeBinary<T>* largest_node(NodeBinary<T>*,NodeBinary<T>*);
    NodeBinary<T>* smallest_node(NodeBinary<T>*,NodeBinary<T>*);
    void null_child(NodeBinary<T> *,NodeBinary<T> *);
    int count_leaves(NodeBinary<T>*);
    int height_of_tree(NodeBinary<T>*);
    int tree_max(NodeBinary<T>*);
    int tree_min(NodeBinary<T>*);
    int evaluate(NodeBinary<T>*);
    int eval(int,int,string);
    bool check_balance(NodeBinary<T>*);
public:
    BinaryTree();
    BinaryTree(T);
    NodeBinary<T>* tree_root();
    void initial();
    bool is_leaf(NodeBinary<T>*);
    bool is_semi_leaf(NodeBinary<T>*);
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
    bool is_balanced();
    bool empty();
    void clear();
    ~BinaryTree();
};


template<class T>
BinaryTree<T>::BinaryTree()
{
    n = 0;
    root = nullptr;
}

template<class T>
BinaryTree<T>::BinaryTree(T d)
{
    n = 1;
    NodeBinary<T>* temp = new NodeBinary<T>(d);
    root = temp;
}

template<class T>
NodeBinary<T> *BinaryTree<T>::tree_root()
{
    return this->root;
}

template<class T>
void BinaryTree<T>::initial()
{
    NodeBinary<T>* temp1 = new NodeBinary<T>("+");
    this->root = temp1;

    NodeBinary<T>* temp2 = new NodeBinary<T>("2");
    this->root->left = temp2;

    NodeBinary<T>* temp3 = new NodeBinary<T>("*");
    this->root->right = temp3;

    NodeBinary<T>* temp4 = new NodeBinary<T>("3");
    this->root->right->left = temp4;

    NodeBinary<T>* temp5 = new NodeBinary<T>("5");
    this->root->right->right = temp5;
}

template<class T>
bool BinaryTree<T>::is_leaf(NodeBinary<T> * node)
{
    return node->left == nullptr && node->right == nullptr;
}

template<class T>
bool BinaryTree<T>::is_semi_leaf(NodeBinary<T> * node)
{
    return node->left == nullptr || node->right == nullptr;
}

template<class T>
void BinaryTree<T>::insert(T d)
{
    if(this->empty())
    {
        NodeBinary<T> * new_node = new NodeBinary<T>(d);
        root = new_node;
        n++;
        return;
    }
    insertAt(root,d);
}

template<class T>
void BinaryTree<T>::remove(T d)
{
    if(this->empty())
        return;
    removeAt(root,nullptr,d);
}

template<class T>
bool BinaryTree<T>::find(T d)
{
    if(this->empty())
        return false;
    return find_node(root,d);
}

template<class T>
void BinaryTree<T>::print_preorder()
{
    if(this->empty())
        return;
    preorder(root);

    cout << endl;
}

template<class T>
void BinaryTree<T>::print_inorder()
{
    if(this->empty())
        return;
    inorder(root);

    cout << endl;
}

template<class T>
void BinaryTree<T>::print_postorder()
{
    if(this->empty())
        return;
    postorder(root);

    cout << endl;
}

template<class T>
int BinaryTree<T>::number_of_leaves()
{
    return count_leaves(root);
}

template<class T>
int BinaryTree<T>::height()
{
    return height_of_tree(root);
}

template<class T>
int BinaryTree<T>::Max()
{
    return tree_max(root);
}

template<class T>
int BinaryTree<T>::Min()
{
    return tree_min(root);
}

template<class T>
int BinaryTree<T>::equation_calculator()
{
    return evaluate(root);
}

template<class T>
bool BinaryTree<T>::is_balanced()
{
    return check_balance(root);
}

template<class T>
void BinaryTree<T>::deleteNode(NodeBinary<T> * node)
{
    if(node == nullptr)
        return;

    deleteNode(node->left);
    deleteNode(node->right);

    n--;
    delete node;
}

template<class T>
void BinaryTree<T>::preorder(NodeBinary<T> * node)
{
    if(node == nullptr)
        return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template<class T>
void BinaryTree<T>::inorder(NodeBinary<T> * node)
{
    if(node == nullptr)
        return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

template<class T>
void BinaryTree<T>::postorder(NodeBinary<T> * node)
{
    if(node == nullptr)
        return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

template<class T>
bool BinaryTree<T>::find_node(NodeBinary<T> * node, T d)
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
void BinaryTree<T>::insertAt(NodeBinary<T> * node, T d)
{
    if(is_semi_leaf(node))
    {
        if(d == node->data)
            return;
        if(d < node->data && node->left == nullptr)
        {
            NodeBinary<T> * new_node = new NodeBinary<T>(d);
            n++;
            node->left = new_node;
            return;
        }
        if(d > node->data && node->right == nullptr)
        {
            NodeBinary<T> * new_node = new NodeBinary<T>(d);
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
void BinaryTree<T>::removeAt(NodeBinary<T> * node,NodeBinary<T> * parent, T d)
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
void BinaryTree<T>::remove_semi_leaf(NodeBinary<T> * node)
{
    if(node->left == nullptr)
    {
        swapel(node->right->data,node->data);
        NodeBinary<T> * temp = node->right;
        node->right = nullptr;
        delete temp;
    }
    else if(node->right == nullptr)
    {
        swapel(node->left->data,node->data);
        NodeBinary<T> * temp = node->left;
        node->left = nullptr;
        delete temp;
    }
    n--;
}

template<class T>
void BinaryTree<T>::remove_subtree(NodeBinary<T> * node)
{
    NodeBinary<T> * small_node_parent = smallest_node(node,node->right);
    node->data = small_node_parent->left->data;

    NodeBinary<T> * temp = small_node_parent->left;
    small_node_parent->left = nullptr;
    delete temp;
    n--;
}

template<class T>
NodeBinary<T> *BinaryTree<T>::largest_node(NodeBinary<T> * parent,NodeBinary<T>* child)
{
    if(child->right == nullptr)
        return parent;
    return largest_node(child,child->right);
}

template<class T>
NodeBinary<T> *BinaryTree<T>::smallest_node(NodeBinary<T> * parent,NodeBinary<T> * child)
{
    if(child->left == nullptr)
        return parent;
    return smallest_node(child,child->left);
}

template<class T>
void BinaryTree<T>::null_child(NodeBinary<T> * node,NodeBinary<T> * parent)
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
int BinaryTree<T>::count_leaves(NodeBinary<T> * node)
{
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;

    return count_leaves(node->left) + count_leaves(node->right);
}

template<class T>
int BinaryTree<T>::height_of_tree(NodeBinary<T> * node)
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
int BinaryTree<T>::tree_max(NodeBinary<T> * node)
{
    if(node->right == nullptr)
        return node->data;
    return tree_max(node->right);
}

template<class T>
int BinaryTree<T>::tree_min(NodeBinary<T> * node)
{
    if(node->left == nullptr)
        return node->data;
    return tree_min(node->left);
}

template<class T>
int BinaryTree<T>::evaluate(NodeBinary<T> * node)
{
    if(node->is_numeric())
        return node->to_numeric();

    int left_subtree = evaluate(node->left);
    int right_subtree = evaluate(node->right);

    return eval(left_subtree,right_subtree,node->data);
}

template<class T>
int BinaryTree<T>::eval(int left_operand, int right_operand, string op)
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
bool BinaryTree<T>::check_balance(NodeBinary<T> * node)
{
    if(node == nullptr)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
        return 1;

    int height_left = height_of_tree(node->left);
    int height_right = height_of_tree(node->right);

    return abs(height_left - height_right) <= 1;
}

template<class T>
bool BinaryTree<T>::empty()
{
    return this->root == nullptr;
}

template<class T>
void BinaryTree<T>::clear()
{
    if(this->empty())
        return;

    deleteNode(root);
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    clear();
}
