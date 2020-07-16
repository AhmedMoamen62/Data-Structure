#pragma once
#include <cstdlib>
template <class T>
class Node_Binary
{
public:
    T data;
    Node_Binary<T>* left;
    Node_Binary<T>* right;
    Node_Binary(T data = 0,Node_Binary<T>* left = nullptr,Node_Binary<T>* right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    bool is_numeric()
    {
        if(this == nullptr)
            return false;
        for(auto c : this->data)
        {
            if(!(c >= '0' && c <= '9'))
                return false;
        }
        return true;
    }
    int to_numeric()
    {
        return atoi(this->data.c_str());
    }
};

