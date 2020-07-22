#pragma once
#include <cstdlib>
template <class T>
class NodeBinary
{
public:
    T data;
    NodeBinary<T>* left;
    NodeBinary<T>* right;
    NodeBinary(T data = 0,NodeBinary<T>* left = nullptr,NodeBinary<T>* right = nullptr)
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

