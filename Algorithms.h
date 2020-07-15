#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <iostream>
using namespace std;

template <typename T>
T binary_search(T,T*,T);
template <typename T>
T find_max(T*,T);
template <typename T>
T sum(T*,T);
template <typename T>
void decimal2binary(T);
template <typename T>
void print_even(T);
template <typename T>
T factorial(T);
template <typename T>
T fibbonaci(T);
template <typename T>
void swapel(T&,T&);
template <typename T>
void bubbl_sort(T,T*);
template <typename T>
void merge_sort(T* arr,T* sorted_arr,int n);
template <typename T>
void merge(T* l_arr,T* r_arr,int l_len,int r_len,T* sorted_arr);


template <typename T>
void swapel(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void bubbl_sort(T n,T* arr)
{
    for(T i = 0; i < n ; i++)
    {
        bool swapped = false;
        for(T j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j + 1]);
                swapped = true;
            }
        }
        if(!swapped)
            return;
    }
}

template <typename T>
T fibbonaci(T n)
{
    if(n <= 1)
    {
        return n;
    }
    return fibbonaci(n - 1) + fibbonaci(n - 2);
}

template <typename T>
T factorial(T n)
{
    if(n == 1 || n == 0)
    {
        return 1;
    }
    return n*factorial(n - 1);
}

template <typename T>
void print_even(T n)
{
    if(n >= 0)
    {
        print_even(n - 2);
        cout << n << " ";
    }
}

template <typename T>
void decimal2binary(T n)
{
    if(n > 0)
    {
        decimal2binary(n/2);
        cout << n%2;
    }
}

// O(n)
template <typename T>
T sum(T* arr,T n)
{
    if(n == 1)
    {
        return arr[0];
    }
    return arr[n - 1] + sum(arr, n - 1);
}
// O(n)
template <typename T>
T find_max(T* arr,T n)
{
    if(n == 1)
    {
        return arr[0];
    }
    return max(arr[n - 1],find_max(arr,n - 1));
}
// O(log n)
template <typename T>
T binary_search(T n,T* arr,T value)
{
    T low = 0;
    T high = n-1;
    while (low <= high)
    {
        T mid = (low + high)/2;
        if(arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else if (arr[mid] > value)
        {
            high = mid - 1;
        }
    }
    return -1;
}

template <typename T>
void merge_sort(T* arr,T* sorted_arr,int n)
{
    if(n == 1)
    {
        sorted_arr[0] = arr[0];
        return;
    }
    int mid = n/2;

    T* l_arr = new T[mid];
    T* r_arr = new T[n - mid];

    T* sorted_l_arr = new T[mid];
    T* sorted_r_arr = new T[n - mid];

    for(int i = 0 ; i < mid ; i++)
        l_arr[i] = arr[i];
    for(int j = mid ; j < n ; j++)
        r_arr[j - mid] = arr[j];

    merge_sort(l_arr,sorted_l_arr,mid);
    merge_sort(r_arr,sorted_r_arr,n - mid);

    merge(sorted_l_arr,sorted_r_arr,mid,n - mid,sorted_arr);

    delete [] l_arr;
    delete [] r_arr;
    delete [] sorted_l_arr;
    delete [] sorted_r_arr;
}
template <typename T>
void merge(T* l_arr,T* r_arr,int l_len,int r_len,T* sorted_arr)
{
    int l = 0,r = 0,index = 0;
    while(l < l_len && r < r_len)
    {
        if(l_arr[l] > r_arr[r])
            sorted_arr[index++] = l_arr[l++];
        else
            sorted_arr[index++] = r_arr[r++];
    }
    while (l < l_len)
        sorted_arr[index++] = l_arr[l++];
    while (r < r_len)
        sorted_arr[index++] = r_arr[r++];
}

#endif // ALGORITHMS_H
