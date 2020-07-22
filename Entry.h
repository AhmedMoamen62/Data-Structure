#pragma once
#include <functional>
#include <string>
using namespace std;

template <class K,class V>
class Entry
{
    int mhash;
    K key;
    V value;
public:
    Entry();
    Entry(K,V);
    int HashEntry(K);
    K getKey();
    void setKey(K);
    void setValue(V);
    V& getValue();
    bool equals(K);
};

template<class K, class V>
Entry<K,V>::Entry()
{

}

template <class K,class V>
Entry<K,V>::Entry(K k,V v)
{
    mhash = HashEntry(k);
    this->key = k;
    this->value = v;
}

template<class K, class V>
int Entry<K,V>::HashEntry(K k)
{
    hash<K> new_hash;
    return new_hash(k);
}

template<class K, class V>
K Entry<K,V>::getKey()
{
    return this->key;
}

template<class K, class V>
void Entry<K,V>::setKey(K k)
{
    key = k;
}

template<class K, class V>
void Entry<K,V>::setValue(V v)
{
    value = v;
}

template<class K, class V>
V& Entry<K,V>::getValue()
{
    return this->value;
}

template<class K, class V>
bool Entry<K,V>::equals(K k)
{
    if(mhash != HashEntry(k))
        return false;
    return key == k;
}


