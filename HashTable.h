#pragma once
#include <functional>
#include "Linkedlist.h"
#include "Entry.h"
using namespace std;

#define DEFAULT_CAPACITY 3
#define DEFAULT_LOAD_FACTOR 0.75

using namespace std;

template <class K,class V>
class HashTable
{
    double maxLoadFactor;
    int capacity,threshold;
    int n = 0;
    Linkedlist<Entry<K,V>> * table;
    int normalizeIndex(K);
    void bucketRemoveEntry(int,K);
    void bucketInsertEntry(int,Entry<K,V>);
    int bucketSeekEntry(int,K);
    void resizeTable();
    int hashEntry(K);
public:
    HashTable(int cap = DEFAULT_CAPACITY, double maxFactor = DEFAULT_LOAD_FACTOR);
    int size();
    bool isEmpty();
    void clear();
    void insert(K,V);
    V& get(K);
    V& operator[](K);
    void remove(K);
    Linkedlist<K> keys();
    Linkedlist<V> values();
    bool containsKey(K);
    ~HashTable();
};

template<class K, class V>
int HashTable<K,V>::normalizeIndex(K Key)
{
    // to remove negative and get index between 0 and capacity of the list
    return (hashEntry(Key) & 0x7FFFFFFF)%capacity;
}

template<class K, class V>
void HashTable<K,V>::bucketInsertEntry(int bucketIndex, Entry<K, V> entry)
{
    int index = bucketSeekEntry(bucketIndex,entry.getKey());
    if(index != -1)
        table[bucketIndex][index].setValue(entry.getValue());
    else
    {
        table[bucketIndex].push_front(entry);
        if(++n > threshold)
            resizeTable();
    }
}

template<class K, class V>
int HashTable<K,V>::bucketSeekEntry(int bucketIndex, K key)
{
    if(table[bucketIndex].empty())
        return -1;
    for(int i = 0 ; i < table[bucketIndex].size() ; i++)
    {
        if(table[bucketIndex][i].equals(key))
            return i;
    }
    return -1;
}

template<class K, class V>
void HashTable<K,V>::resizeTable()
{
    int old_cap = capacity;
    capacity *= 2;
    threshold = capacity*maxLoadFactor;

    Linkedlist<Entry<K,V>> * newTable = new Linkedlist<Entry<K,V>>[capacity];

    for(int i = 0 ; i < old_cap ; i++)
    {
        if(!table[i].empty())
        {
            for(int j = 0 ; j < table[i].size() ; j++)
            {
                K key = table[i][j].getKey();
                int bucketIndex = normalizeIndex(key);
                newTable[bucketIndex].push_back(table[i][j]);
            }
            table[i].clear();
        }
    }
    table = newTable;
}

template<class K, class V>
int HashTable<K,V>::hashEntry(K key)
{
    hash<K> new_hash;
    return new_hash(key);
}

template<class K, class V>
void HashTable<K,V>::bucketRemoveEntry(int bucketIndex, K key)
{
    if(table[bucketIndex].empty())
        return;
    int index = bucketSeekEntry(bucketIndex,key);
    if(index == -1)
        return;
    table[bucketIndex].removeAt(index);
    n--;
}
template<class K, class V>
HashTable<K,V>::HashTable(int cap, double maxFactor)
{
    maxLoadFactor = maxFactor;
    capacity = max(cap,DEFAULT_CAPACITY);
    threshold = maxLoadFactor*capacity;
    table = new Linkedlist<Entry<K,V>>[capacity];
}

template<class K, class V>
int HashTable<K,V>::size()
{
    return n;
}

template<class K, class V>
bool HashTable<K,V>::isEmpty()
{
    return n == 0;
}

template<class K, class V>
void HashTable<K,V>::clear()
{
    for(int i = 0 ; i < capacity ; i++)
    {
        if(!table[i].empty())
        {
            table[i].clear();
        }
    }
    n = 0;
}

template<class K, class V>
void HashTable<K,V>::insert(K key, V value)
{
    int bucketIndex = normalizeIndex(key);
    bucketInsertEntry(bucketIndex,Entry<K,V>(key,value));
}

template<class K, class V>
V& HashTable<K,V>::get(K key)
{
    int bucketIndex = normalizeIndex(key);
    int index = bucketSeekEntry(bucketIndex,key);
    if(index != -1)
        return table[bucketIndex][index].getValue();
}

template<class K, class V>
V& HashTable<K,V>::operator[](K key)
{
    return get(key);
}

template<class K, class V>
void HashTable<K,V>::remove(K key)
{
    int bucketIndex = normalizeIndex(key);
    bucketRemoveEntry(bucketIndex,key);
}

template<class K, class V>
Linkedlist<K> HashTable<K,V>::keys()
{
    Linkedlist<K> key;

    for(int i = 0 ; i < capacity ; i++)
    {
        if(!table[i].empty())
        {
            for(int j = 0 ; j < table[i].size() ; j++)
            {
                key.push_back(table[i][j].getKey());
            }
        }
    }
    return key;
}

template<class K, class V>
Linkedlist<V> HashTable<K,V>::values()
{
    Linkedlist<V> value;

    for(int i = 0 ; i < capacity ; i++)
    {
        if(!table[i].empty())
        {
            for(int j = 0 ; j < table[i].size() ; j++)
            {
                value.push_back(table[i][j].getValue());
            }
        }
    }
    return value;
}

template<class K, class V>
bool HashTable<K,V>::containsKey(K key)
{
    int bucketIndex = normalizeIndex(key);
    return bucketSeekEntry(bucketIndex,key) != -1;
}

template <class K,class V>
HashTable<K,V>::~HashTable()
{
    clear();
}
