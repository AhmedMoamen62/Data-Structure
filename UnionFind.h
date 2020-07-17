#pragma once
#include <iostream>
#include <map>
using namespace std;

template <class T>
class UnionFind
{
    map<T,int> sz;
    map<T,int> id;
    int n,numComponents; //size
public:
    UnionFind(int,T*);
    int find(T);
    bool connected(T,T);
    int componentSize(T);
    int size();
    int components();
    void unify(T,T);
};

template <class T>
UnionFind<T>::UnionFind(int size,T* ID)
{
    n = size;
    numComponents = size;

    for(int i = 0 ; i < size ; i++)
    {
        sz[ID[i]] = 1;
        id[ID[i]] = i;
    }
}

template <class T>
int UnionFind<T>::find(T p)
{
    int root = id[p];

    while(root != id[p])
        root = id[p];

    while(id[p] != root)
    {
        int next = id[p];
        id[p] = root;
        p = next;
    }

    return root;
}

template <class T>
bool UnionFind<T>::connected(T p, T q)
{
    return find(p) == find(q);
}

template <class T>
int UnionFind<T>::componentSize(T p)
{
    return sz[p];
}

template <class T>
int UnionFind<T>::size()
{
    return n;
}

template <class T>
int UnionFind<T>::components()
{
    return numComponents;
}

template <class T>
void UnionFind<T>::unify(T p, T q)
{
    int root1 = find(p);
    int root2 = find(q);

    if(root1 == root2)
        return;

    if(sz[p] < sz[q])
    {
        sz[q] += sz[p];
        id[p] = root2;
    }
    else
    {
        sz[p] += sz[q];
        id[q] = root1;
    }

    numComponents--;
}

